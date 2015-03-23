MEMORY_SIZE       ^("Memory Size: ") 
MANAGEMENT_POLICY ^("Memory Management Policy: ")
POLICY_PARAM      ^("Policy Parameter: ") 
PROCESS_ID        ^("Process ID: ")
ARRIVAL_TIME      ^("Arrival Time: ") 
LIFETIME          ^("Lifetime in Memory: ")
ADDRESS_SPACE     ^("Address Space: ")
EOL [0-9]+$
%%

{MEMORY_SIZE}       return (1);
{MANAGEMENT_POLICY} return (2);
{POLICY_PARAM}      return (3);
{PROCESS_ID}        return (4);
{ARRIVAL_TIME}      return (5);
{LIFETIME}          return (6);
{ADDRESS_SPACE}     return (7);
{EOL}               return (8);

%%

void yerror() {
  printf("Error during parsing\n");
  exit(0);
}

int yywrap() {}
