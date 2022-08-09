#include <open62541.h>
#include <signal.h>
#include <stdlib.h>
//#include <pigpio.h>


static volatile UA_Boolean running = true;
static void stopHandler(int sig) {
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "received ctrl-c");
    running = false;
}

static UA_StatusCode
Add_objects(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output){

UA_String *nodeid = (UA_String *) input[0].data;
char * nodeId =  (char *)UA_malloc(sizeof(char)*nodeid->length+1);
memcpy(nodeId,nodeid->data, nodeid->length);
UA_Int32 len = *(UA_Int32 *) nodeid->length;
nodeId[len] = '\0';

UA_Int64 pin_number = * (UA_Int64 *) input[1].data;

UA_Int16 ns_room1 = UA_Server_addNamespace(server, "Room1");
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "New Namespace added with %d",ns_room1);

UA_NodeId GPIO_Id;
UA_ObjectAttributes oAttr = UA_ObjectAttributes_default;
UA_Server_addObjectNode(server, UA_NODEID_STRING(2,"GPIO"),
                        UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                        UA_NODEID_NUMERIC(0, UA_NS0ID_ORGANIZES),
                        UA_QUALIFIEDNAME(2, "GPIO"), UA_NODEID_NUMERIC(0, UA_NS0ID_BASEOBJECTTYPE),
                        oAttr, NULL, &GPIO_Id);

UA_VariableAttributes tAttr = UA_VariableAttributes_default;
//UA_Int64 state = gpioRead(pin_number);
UA_Int64 state = 1;
UA_Variant_setScalar(&tAttr.value, &state, &UA_TYPES[UA_TYPES_INT64]);
UA_Server_addVariableNode(server, UA_NODEID_STRING(2,nodeId), GPIO_Id,
                          UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                          UA_QUALIFIEDNAME(2,nodeId),
                          UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), tAttr, NULL, NULL);



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
    UA_Variant_setScalarCopy(output, &state, &UA_TYPES[UA_TYPES_INT32]);
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
    UA_Variant_setScalarCopy(output, &state, &UA_TYPES[UA_TYPES_INT32]);
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

     //gpioPWM(pin_number,255*duty_cycle);
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
    inputArguments[1].dataType = UA_TYPES[UA_TYPES_INT64].typeId;
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

    UA_Int16 ns_room1 = UA_Server_addNamespace(server, "Room1");
UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "New Namespace added with %d",ns_room1);

UA_Argument inputArguments2[2];

UA_Argument_init(&inputArguments2[0]);
inputArguments2[0].description = UA_LOCALIZEDTEXT("en-US", "NODEID");
inputArguments2[0].name = UA_STRING("NODEID");
inputArguments2[0].dataType = UA_TYPES[UA_TYPES_STRING].typeId;
inputArguments2[0].valueRank = UA_VALUERANK_SCALAR;

UA_Argument_init(&inputArguments2[1]);
inputArguments2[1].description = UA_LOCALIZEDTEXT("en-US", "GPIO");
inputArguments2[1].name = UA_STRING("GPIO");
inputArguments2[1].dataType = UA_TYPES[UA_TYPES_INT64].typeId;
inputArguments2[1].valueRank = UA_VALUERANK_SCALAR;


UA_MethodAttributes OAttr = UA_MethodAttributes_default;
OAttr.description = UA_LOCALIZEDTEXT("en-US","ADD OBJECT");
OAttr.displayName = UA_LOCALIZEDTEXT("en-US","ADD OBJECT");
OAttr.executable = true;
OAttr.userExecutable = true;
UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62544),
                        UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                        UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                        UA_QUALIFIEDNAME(1, "ADD OBJECT"),
                        OAttr, &Add_objects,
                        2, inputArguments2, 0, NULL, NULL, NULL);

  UA_StatusCode retval = UA_Server_run(server, &running);
    UA_Server_delete(server);
    return retval == UA_STATUSCODE_GOOD ? EXIT_SUCCESS : EXIT_FAILURE;
}
