#include "memory_manager.h"

void init_memory_manager() {
  head = (MemoryNode*) malloc(sizeof(MemoryNode*)); 

  head -> next = NULL;
  head -> block = NULL;

  //Read in the inputs to actually setup the 
  //memory manager.
  int token;
  while((token = read_input()) != -1) {
    switch(token) {
      case MEMORY_SIZE:
        debug("Setting memory size\n");
        char* mem_size = get_token();
        MAX_SIZE = atoi(mem_size);
        break;
      case MEMORY_POLICY:
        debug("Setting memory policy\n");
        int v = get_token_value();
        switch(v) {
          case VSP_TOKEN:
            debug("Setting policy to VSP\n");
            mem_policy = VSP;
            break;
          case PAG_TOKEN:
            debug("Setting policy to PAG\n");
            mem_policy = PAG;
            break;
          case SEG_TOKEN:
            debug("Setting policy to SEG\n");
            mem_policy = SEG;
            break;
        }
        break;
      case POLICY:
        debug("Setting memory policy parameter\n");
        //Have to get token here because
        //the params are [0-2] which is tokenized by
        // the EOL regex.
        int param = atoi(get_token());
        switch(param) {
          case FF_TOKEN:
            debug("Setting parameter to FF\n");
            mem_policy_parameter = FF;
            break;
          case BF_TOKEN:
            debug("Setting parameter to BF\n");
            mem_policy_parameter = BF;
            break;
          case WF_TOKEN:
            debug("Setting parameter to WF\n");
            mem_policy_parameter = WF;
            break;
          default:
            //Need a default case because I'm not really sure
            //What the behavior is for PAG with no parameter.
            debug("No parameter specified\n");
            break;
        }
        break;
    }
  }
}
