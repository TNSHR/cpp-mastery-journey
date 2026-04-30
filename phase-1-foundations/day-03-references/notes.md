#Day 3 - Reference 
## Defination 
A refrence is and alias (another name) for an existing variable
## Example 
int a  = 10;
int& r = a;

##Key Points
-Refrence must be initialized
-Cannot be null
-Cannot be reassigned
-Acts as alias

## Refrence vs pointer
-pointer stored address
-reference is alias
##Pass by Refrence 
Used to modify original variable without copying
##Example 
void update(int& x){
    x = x + 10;
}
##Key Learning
Reference provides safer and cleaner alternative to pointers