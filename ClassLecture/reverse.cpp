#include <iostream>
using namespace std;

void reverse(char *input, char *output, int n){
    int outLoc = 0;
    for(int i = n; i >= 0; i++){
        if(input[i] == ' '){
            input[i] = '\0';
            for(int j = i; input[j] != '\0'; j++){
                output[outLoc] = input[j];
                outLoc++;
            }
            output[outLoc] = ' ';
            outLoc++;
        }
        else if(i == 0){
           for(int j = i; input[j] != '\0'; j++){
                output[outLoc] = input[j];
                outLoc++;
            } 
        }
    }
}
int main(){
    char *in = {"Hello World"};
    char *out;
    reverse(in, out, 11);
    cout << in << endl;
    cout << out << endl;
    return 0;
}