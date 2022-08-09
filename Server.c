#include <open62541.h>
#include <signal.h>
#include <stdlib.h>

UA_Double temperature = 50.0;

static volatile UA_Boolean running = true;
static void stopHandler(int sig) {
	    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "received ctrl-c");
	        running = false;
}

static void
beforeReadTime(UA_Server *server,
		               const UA_NodeId *sessionId, void *sessionContext,
			                      const UA_NodeId *nodeid, void *nodeContext,
					                     const UA_NumericRange *range, const UA_DataValue *data) {

	    float tmp = 1.0 * (rand()%100)/100 -0.5;
	        temperature +=tmp;
		    UA_Variant value;
		        UA_Variant_setScalar(&value, &temperature, &UA_TYPES[UA_TYPES_DOUBLE]);
			    UA_Server_writeValue(server, UA_NODEID_STRING(2,"Temperature"), value);
}

static void
afterWriteTime(UA_Server *server,
		               const UA_NodeId *sessionId, void *sessionContext,
			                      const UA_NodeId *nodeId, void *nodeContext,
					                     const UA_NumericRange *range, const UA_DataValue *data) {

	    UA_Variant value;
	        UA_Int64 state;
		    UA_Server_readValue(server, UA_NODEID_STRING(2,"led"), &value);
		        state = *(UA_Int64*) value.data;
			    if (state == 1) UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,"LED 0");
			        else UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,"LED 1");
}



int main(void) {
	    signal(SIGINT, stopHandler);
	        signal(SIGTERM, stopHandler);

		    UA_Server *server = UA_Server_new();
		        UA_ServerConfig_setDefault(UA_Server_getConfig(server));


			    UA_Int16 ns_room1 = UA_Server_addNamespace(server, "Room1");
			        UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "New Namespace added with %d",ns_room1);

				    UA_NodeId temp_sen_Id; /* get the nodeid assigned by the server */
				        UA_ObjectAttributes oAttr = UA_ObjectAttributes_default;
					    UA_Server_addObjectNode(server, UA_NODEID_STRING(2,"Temperature Sensor"),
							                                UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
											                            UA_NODEID_NUMERIC(0, UA_NS0ID_ORGANIZES),
														                                UA_QUALIFIEDNAME(2, "Temperature Sensor"), UA_NODEID_NUMERIC(0, UA_NS0ID_BASEOBJECTTYPE),
																		                            oAttr, NULL, &temp_sen_Id);

					        UA_VariableAttributes tAttr = UA_VariableAttributes_default;
						    UA_Variant_setScalar(&tAttr.value, &temperature, &UA_TYPES[UA_TYPES_DOUBLE]);
						        UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"Temperature"), temp_sen_Id,
									                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
												                                    UA_QUALIFIEDNAME(2,"Temperature"),
																                                  UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), tAttr, NULL, NULL);


							    UA_NodeId led_Id; /* get the nodeid assigned by the server */
							        UA_ObjectAttributes o_Attr = UA_ObjectAttributes_default;
								    UA_Server_addObjectNode(server, UA_NODEID_STRING(2,"LED"),
										                                UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
														                            UA_NODEID_NUMERIC(0, UA_NS0ID_ORGANIZES),
																	                                UA_QUALIFIEDNAME(2,"LED"), UA_NODEID_NUMERIC(0, UA_NS0ID_BASEOBJECTTYPE),
																					                            o_Attr, NULL, &led_Id);

								        UA_VariableAttributes lAttr = UA_VariableAttributes_default;
									    UA_Int64 led = 0;
									        UA_Variant_setScalar(&lAttr.value, &led, &UA_TYPES[UA_TYPES_INT64]);
										    lAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
										        UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"led"), led_Id,
													                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
																                                    UA_QUALIFIEDNAME(2,"led"),
																				                                  UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), lAttr, NULL, NULL);


											    UA_ValueCallback callback1 ;
											        callback1.onRead = beforeReadTime;
												    callback1.onWrite = NULL;
												        UA_Server_setVariableNode_valueCallback(server, UA_NODEID_STRING(2,"led"), callback1);

													    UA_ValueCallback callback2 ;
													        callback2.onRead = NULL;
														    callback2.onWrite = afterWriteTime;
														        UA_Server_setVariableNode_valueCallback(server, UA_NODEID_STRING(2,"Temperature Sensor"), callback2);


															    UA_StatusCode retval = UA_Server_run(server, &running);

															        UA_Server_delete(server);
																    return retval == UA_STATUSCODE_GOOD ? EXIT_SUCCESS : EXIT_FAILURE;
}

