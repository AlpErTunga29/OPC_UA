#include <open62541.h>
#include <signal.h>
#include <stdlib.h>
//#include <pigpio.h>
//#include <math.h>

static volatile UA_Boolean running = true;
static void stopHandler(int sig) {
	UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "received ctrl-c");
	running = false;
}



static void
beforeRead(UA_Server *server,
               const UA_NodeId *sessionId, void *sessionContext,
               const UA_NodeId *nodeid, void *nodeContext,
               const UA_NumericRange *range, const UA_DataValue *data) {
    
	UA_Int64 now = rand() % 2;
	//now = gpioRead(0);
        UA_Variant value;
    	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
        UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 0"), value);
	
	now = rand() % 2;
	//now = gpioRead(1);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 1"), value);
	now = rand() % 2;
	//now = gpioRead(2); 
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 2"), value); 
	now = rand() % 2;
	//now = gpioRead(3);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]); 
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 3"), value); 

	now = rand() % 2;
	//now = gpioRead(4);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 4"), value); 
	now = rand() % 2;
	//now = gpioRead(5);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 5"), value); 
	now = rand() % 2;
	//now = gpioRead(6);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 6"), value); 

	now = rand() % 2;
	//now = gpioRead(7);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 7"), value);
	now = rand() % 2;
	//now = gpioRead(8);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 8"), value);
	now = rand() % 2;
	//now = gpioRead(9);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 9"), value);
	
	now = rand() % 2;
	//now = gpioRead(10);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 10"), value);
	now = rand() % 2;
	//now = gpioRead(11);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 11"), value); 
	now = rand() % 2;
	//now = gpioRead(12);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 12"), value);
	
	now = rand() % 2;
	//now = gpioRead(13);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 13"), value);
	now = rand() % 2;
	//now = gpioRead(14);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 14"), value);
	now = rand() % 2;
	//now = gpioRead(15);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 15"), value);
	
	now = rand() % 2;
	//now = gpioRead(16);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 16"), value); 
	now = rand() % 2;
	//now = gpioRead(17);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 17"), value);
	now = rand() % 2;
	//now = gpioRead(18);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 18"), value);
	
	now = rand() % 2;
	//now = gpioRead(19);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 19"), value);
	now = rand() % 2;
	//now = gpioRead(20);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 20"), value);
	now = rand() % 2;
	//now = gpioRead(21);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 21"), value); 
	
	now = rand() % 2;
	//now = gpioRead(22);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 22"), value);
	now = rand() % 2;
	//now = gpioRead(23);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 23"), value);
	now = rand() % 2;
	//now = gpioRead(24);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 24"), value);
	
	now = rand() % 2;
	//now = gpioRead(25);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 25"), value);
	now = rand() % 2;
	//now = gpioRead(26);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 26"), value); 
	now = rand() % 2;
	//now = gpioRead(27);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 27"), value);
	
	now = rand() % 2;
	//now = gpioRead(28);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 28"), value);
	now = rand() % 2;
	//now = gpioRead(29);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 29"), value);
	now = rand() % 2;
	//now = gpioRead(30);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 30"), value);
	
	now = rand() % 2;
	//now = gpioRead(31);
	UA_Variant_setScalar(&value, &now, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_writeValue(server, UA_NODEID_STRING(2, "GPIO 31"), value); 

}




static UA_StatusCode
set_high(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output){

	UA_Int64 state = 1;
	UA_Int64 pin_number = * (UA_Int64 *) input[0].data;

	//gpioWrite(pin_number, state);
	UA_Variant_setScalarCopy(output, &state, &UA_TYPES[UA_TYPES_INT64]);
	printf("GPIO %ld: %ld\n", pin_number,state);

	return UA_STATUSCODE_GOOD;
}

static UA_StatusCode
set_low(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output){

	UA_Int64 state = 0;
	UA_Int64 pin_number = * (UA_Int64 *) input[0].data;

	//gpioWrite(pin_number, state);
	UA_Variant_setScalarCopy(output, &state, &UA_TYPES[UA_TYPES_INT64]);
	printf("GPIO %ld: %ld\n", pin_number,state);

	return UA_STATUSCODE_GOOD;

}

static UA_StatusCode
set_pwm(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output){


	UA_Int64 pin_number = * (UA_Int64 *) input[0].data;
	UA_Double duty_cycle = * (UA_Double *) input[1].data;
	UA_Int64 frequency = * (UA_Int64 *) input[2].data; 	

	//gpioPWM(pin_number,ceil(255*duty_cycle));
	//gpioSetPWMfrequency(pin_number,frequency);
	UA_Variant_setScalarCopy(&output[0], &duty_cycle, &UA_TYPES[UA_TYPES_DOUBLE]);
	UA_Variant_setScalarCopy(&output[1], &frequency, &UA_TYPES[UA_TYPES_INT64]);
	printf("Duty cycle: %.2f and frequency: %ld",duty_cycle*100,frequency);

	return UA_STATUSCODE_GOOD;

}



int main(void) {
	signal(SIGINT, stopHandler);
	signal(SIGTERM, stopHandler);

	UA_Server *server = UA_Server_new();
	UA_ServerConfig_setDefault(UA_Server_getConfig(server));


	UA_Argument inputArguments[3];

	UA_Argument_init(&inputArguments[0]);
	inputArguments[0].description = UA_LOCALIZEDTEXT("en-US", "GPIO PIN");
	inputArguments[0].name = UA_STRING("GPIO PIN");
	inputArguments[0].dataType = UA_TYPES[UA_TYPES_INT64].typeId;
	inputArguments[0].valueRank = UA_VALUERANK_SCALAR;

	UA_Argument_init(&inputArguments[1]);
	inputArguments[1].description = UA_LOCALIZEDTEXT("en-US", "DUTY CYCLE");
	inputArguments[1].name = UA_STRING("DUTY CYCLE");
	inputArguments[1].dataType = UA_TYPES[UA_TYPES_DOUBLE].typeId;
	inputArguments[1].valueRank = UA_VALUERANK_SCALAR;

	UA_Argument_init(&inputArguments[2]);
	inputArguments[2].description = UA_LOCALIZEDTEXT("en-US", "FREQUENCY");
	inputArguments[2].name = UA_STRING("FREQUENCY");
	inputArguments[2].dataType = UA_TYPES[UA_TYPES_INT64].typeId;
	inputArguments[2].valueRank = UA_VALUERANK_SCALAR;



	UA_Argument outputArgument;

	  UA_Argument_init(&outputArgument);
	outputArgument.description = UA_LOCALIZEDTEXT("en-US", "Digital Output");
	outputArgument.name = UA_STRING("Digital Output");
	outputArgument.dataType = UA_TYPES[UA_TYPES_INT64].typeId;
	outputArgument.valueRank = UA_VALUERANK_SCALAR;

	UA_Argument outputArgument1[2];

	  UA_Argument_init(&outputArgument1[0]);
	outputArgument1[0].description = UA_LOCALIZEDTEXT("en-US", "Duty Cycle");
	outputArgument1[0].name = UA_STRING("Duty Cycle");
	outputArgument1[0].dataType = UA_TYPES[UA_TYPES_DOUBLE].typeId;
	outputArgument1[0].valueRank = UA_VALUERANK_SCALAR;

	  UA_Argument_init(&outputArgument1[1]);
	outputArgument1[1].description = UA_LOCALIZEDTEXT("en-US", "Frequency");
	outputArgument1[1].name = UA_STRING("Frequency");
	outputArgument1[1].dataType = UA_TYPES[UA_TYPES_INT64].typeId;
	outputArgument1[1].valueRank = UA_VALUERANK_SCALAR;


	UA_Int16 ns_room1 = UA_Server_addNamespace(server, "Room1");
	UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "New Namespace added with %d",ns_room1);

	UA_NodeId GPIO_Id;
	UA_ObjectAttributes oAttr = UA_ObjectAttributes_default;
	UA_Server_addObjectNode(server, UA_NODEID_STRING(2,"GPIO"),
	                    UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
	                    UA_NODEID_NUMERIC(0, UA_NS0ID_ORGANIZES),
	                    UA_QUALIFIEDNAME(2, "GPIO"), UA_NODEID_NUMERIC(0, UA_NS0ID_BASEOBJECTTYPE),
	                    oAttr, NULL, &GPIO_Id);

	UA_VariableAttributes Attr0 = UA_VariableAttributes_default;
        //UA_Int64 state = gpioRead(pin_number);
        UA_Int64 state0 = rand() % 2;
        UA_Variant_setScalar(&Attr0.value, &state0, &UA_TYPES[UA_TYPES_INT64]);
        UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 0"), GPIO_Id,
                              UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                              UA_QUALIFIEDNAME(2,"GPIO 0"),
                              UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), Attr0, NULL, NULL);

	UA_VariableAttributes Attr1 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state1 = rand() % 2;
	UA_Variant_setScalar(&Attr1.value, &state1, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 1"), GPIO_Id,
	                      UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	                      UA_QUALIFIEDNAME(2,"GPIO 1"),
	                      UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), Attr1, NULL, NULL);

	UA_VariableAttributes Attr2 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state2 = 0;
	UA_Variant_setScalar(&Attr2.value, &state2, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 2"), GPIO_Id,
	                      UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	                      UA_QUALIFIEDNAME(2,"GPIO 2"),
	                      UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), Attr2, NULL, NULL);



	UA_VariableAttributes Attr3 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state3 = 1;
	UA_Variant_setScalar(&Attr3.value, &state3, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 3"), GPIO_Id,
	                      UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	                      UA_QUALIFIEDNAME(2,"GPIO 3"),
	                      UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), Attr3, NULL, NULL);


	UA_VariableAttributes Attr4 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state4 = 0;
	UA_Variant_setScalar(&Attr4.value, &state4, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 4"), GPIO_Id,
	                      UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	                      UA_QUALIFIEDNAME(2,"GPIO 4"),
	                      UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), Attr4, NULL, NULL);

	UA_VariableAttributes Attr5 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state5 = 1;
	UA_Variant_setScalar(&Attr5.value, &state5, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 5"), GPIO_Id,
	                      UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	                      UA_QUALIFIEDNAME(2,"GPIO 5"),
	                      UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), Attr5, NULL, NULL);



	UA_VariableAttributes Attr6 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state6 = 1;
	UA_Variant_setScalar(&Attr6.value, &state6, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 6"), GPIO_Id,
	                      UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	                      UA_QUALIFIEDNAME(2,"GPIO 6"),
	                      UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), Attr6, NULL, NULL);

	UA_VariableAttributes Attr7 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state7 = rand() % 2;
	UA_Variant_setScalar(&Attr7.value, &state7, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 7"), GPIO_Id,
	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	UA_QUALIFIEDNAME(2,"GPIO 7"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
	Attr7, NULL, NULL);

	UA_VariableAttributes Attr8 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state8 = 0;
	UA_Variant_setScalar(&Attr8.value, &state8, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 8"), GPIO_Id,
	      UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	       UA_QUALIFIEDNAME(2,"GPIO 8"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), Attr8, NULL, NULL);

	UA_VariableAttributes Attr9 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number); 
	UA_Int64 state9 = 0;   
	UA_Variant_setScalar(&Attr9.value, &state9, &UA_TYPES[UA_TYPES_INT64]); 
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 9"), GPIO_Id,
	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT), 
	UA_QUALIFIEDNAME(2,"GPIO 9"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), Attr9, NULL, NULL); 
	        
	UA_VariableAttributes Attr10 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state10 = rand() % 2;
	UA_Variant_setScalar(&Attr10.value, &state10, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 10"), GPIO_Id,
	             UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	             UA_QUALIFIEDNAME(2,"GPIO 10"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
	               Attr10, NULL, NULL);
	                
	UA_VariableAttributes Attr11 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state11 = 0;
	UA_Variant_setScalar(&Attr11.value, &state11, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 11"), GPIO_Id,
	                      UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	                       UA_QUALIFIEDNAME(2,"GPIO 11"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), Attr11, NULL, NULL);

	UA_VariableAttributes Attr12 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state12 = rand() % 2;
	UA_Variant_setScalar(&Attr12.value, &state12, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 12"), GPIO_Id,
	                             UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	                             UA_QUALIFIEDNAME(2,"GPIO 12"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
	                               Attr12, NULL, NULL);
	                                
	UA_VariableAttributes Attr13 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state13 = rand() % 2;
	UA_Variant_setScalar(&Attr13.value, &state13, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 13"), GPIO_Id,
	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	UA_QUALIFIEDNAME(2,"GPIO 13"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), Attr13, NULL, NULL);

	UA_VariableAttributes Attr14 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state14 = rand() % 2;
	UA_Variant_setScalar(&Attr14.value, &state14, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 14"), GPIO_Id,
	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	UA_QUALIFIEDNAME(2,"GPIO 14"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
	Attr14, NULL, NULL);
	UA_VariableAttributes Attr15 = UA_VariableAttributes_default;  
	UA_Int64 state15 = 0;
	UA_Variant_setScalar(&Attr15.value, &state15, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 15"), GPIO_Id,
	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	UA_QUALIFIEDNAME(2,"GPIO 15"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), Attr15, NULL, NULL);

	UA_VariableAttributes Attr16 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state16 = rand() % 2;
	UA_Variant_setScalar(&Attr16.value, &state16, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 16"), GPIO_Id,
	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	UA_QUALIFIEDNAME(2,"GPIO 16"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
	Attr16, NULL, NULL);

	UA_VariableAttributes Attr17 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state17 = 0;
	UA_Variant_setScalar(&Attr17.value, &state17, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 17"), GPIO_Id,
	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	UA_QUALIFIEDNAME(2,"GPIO 17"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), Attr17, NULL, NULL);

	UA_VariableAttributes Attr18 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state18 = rand() % 2;
	UA_Variant_setScalar(&Attr18.value, &state18, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 18"), GPIO_Id,
	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	UA_QUALIFIEDNAME(2,"GPIO 18"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
	Attr18, NULL, NULL);

	UA_VariableAttributes Attr19 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state19 = 0;
	UA_Variant_setScalar(&Attr19.value, &state19, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 19"), GPIO_Id,
	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	UA_QUALIFIEDNAME(2,"GPIO 19"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), Attr19, NULL, NULL);

	UA_VariableAttributes Attr20 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state20 = rand() % 2;
	UA_Variant_setScalar(&Attr20.value, &state20, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 20"), GPIO_Id,
	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	UA_QUALIFIEDNAME(2,"GPIO 20"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
	Attr20, NULL, NULL);

	UA_VariableAttributes Attr21 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state21 = 0;
	UA_Variant_setScalar(&Attr21.value, &state21, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 21"), GPIO_Id,
	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	UA_QUALIFIEDNAME(2,"GPIO 21"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), Attr21, NULL, NULL);

	UA_VariableAttributes Attr22 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state22 = rand() % 2;
	UA_Variant_setScalar(&Attr22.value, &state22, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 22"), GPIO_Id,
	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	UA_QUALIFIEDNAME(2,"GPIO 22"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
	Attr22, NULL, NULL);

	UA_VariableAttributes Attr23 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state23 = 0;
	UA_Variant_setScalar(&Attr23.value, &state23, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 23"), GPIO_Id,
	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	UA_QUALIFIEDNAME(2,"GPIO 23"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), Attr23, NULL, NULL);

	UA_VariableAttributes Attr24 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state24 = rand() % 2;
	UA_Variant_setScalar(&Attr24.value, &state24, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 24"), GPIO_Id,
	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	UA_QUALIFIEDNAME(2,"GPIO 24"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
	Attr24, NULL, NULL);

	UA_VariableAttributes Attr25 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state25 = 0;
	UA_Variant_setScalar(&Attr25.value, &state25, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 25"), GPIO_Id,
	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	UA_QUALIFIEDNAME(2,"GPIO 25"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), Attr25, NULL, NULL);

	UA_VariableAttributes Attr26 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state26 = rand() % 2;
	UA_Variant_setScalar(&Attr26.value, &state26, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 26"), GPIO_Id,
	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	UA_QUALIFIEDNAME(2,"GPIO 26"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
	Attr26, NULL, NULL);

	UA_VariableAttributes Attr27 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state27 = 0;
	UA_Variant_setScalar(&Attr27.value, &state27, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 27"), GPIO_Id,
	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	UA_QUALIFIEDNAME(2,"GPIO 27"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), Attr27, NULL, NULL);

	UA_VariableAttributes Attr28 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state28 = 0;
	UA_Variant_setScalar(&Attr28.value, &state28, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 28"), GPIO_Id,
	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	UA_QUALIFIEDNAME(2,"GPIO 28"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), Attr28, NULL, NULL);

	UA_VariableAttributes Attr29 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state29 = rand() % 2;
	UA_Variant_setScalar(&Attr29.value, &state29, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 29"), GPIO_Id,
	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	UA_QUALIFIEDNAME(2,"GPIO 29"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
	Attr29, NULL, NULL);

	UA_VariableAttributes Attr30 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state30 = 0;
	UA_Variant_setScalar(&Attr30.value, &state30, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 30"), GPIO_Id,
	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	UA_QUALIFIEDNAME(2,"GPIO 30"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), Attr30, NULL, NULL);

	UA_VariableAttributes Attr31 = UA_VariableAttributes_default;
	//UA_Int64 state = gpioRead(pin_number);
	UA_Int64 state31 = 0;
	UA_Variant_setScalar(&Attr31.value, &state31, &UA_TYPES[UA_TYPES_INT64]);
	UA_Server_addVariableNode(server, UA_NODEID_STRING(2,"GPIO 31"), GPIO_Id,
	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	UA_QUALIFIEDNAME(2,"GPIO 31"),UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), Attr31, NULL, NULL);


	UA_MethodAttributes highAttr = UA_MethodAttributes_default;
	highAttr.description = UA_LOCALIZEDTEXT("en-US","Method to set high");
	highAttr.displayName = UA_LOCALIZEDTEXT("en-US","Set High");
	highAttr.executable = true;
	highAttr.userExecutable = true;
	UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62541),
	    UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
	    UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	    UA_QUALIFIEDNAME(1, "Set high"),
	    highAttr, &set_high,
	    1, inputArguments, 1, &outputArgument, NULL, NULL);


	UA_MethodAttributes lowAttr = UA_MethodAttributes_default;
	lowAttr.description = UA_LOCALIZEDTEXT("en-US","Method to set low");
	lowAttr.displayName = UA_LOCALIZEDTEXT("en-US","Set Low");
	lowAttr.executable = true;
	lowAttr.userExecutable = true;
	UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62542),
	    UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
	    UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	    UA_QUALIFIEDNAME(1, "Set high"),
	    lowAttr, &set_low,
	    1, inputArguments,  1, &outputArgument, NULL, NULL);

	UA_MethodAttributes pwmAttr = UA_MethodAttributes_default;
	pwmAttr.description = UA_LOCALIZEDTEXT("en-US","Method to set pwm");
	pwmAttr.displayName = UA_LOCALIZEDTEXT("en-US","Set PWM");
	pwmAttr.executable = true;
	pwmAttr.userExecutable = true;
	UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62543),
	    UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
	    UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
	    UA_QUALIFIEDNAME(1, "Set pwm"),
	    pwmAttr, &set_pwm,
	    3, inputArguments, 2, outputArgument1, NULL, NULL);

	UA_ValueCallback callback;
	callback.onRead = beforeRead;
	callback.onWrite = NULL;
	UA_Server_setVariableNode_valueCallback(server, UA_NODEID_STRING(2,"GPIO 0"), callback);

	UA_StatusCode retval = UA_Server_run(server, &running);
	UA_Server_delete(server);
    	return retval == UA_STATUSCODE_GOOD ? EXIT_SUCCESS : EXIT_FAILURE;
}

