#include<iostream>

#include<string>

using namespace std;

void fastio(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

}

string input, result;

int lenOfchar(char c){

    switch(c){

        case 'i':

        case 'o':

            return 2;

        case 'c':

        case 'l':

        case 't':

            return 3;

        case 'e':

        case 'j':

        case 'm':

        case 'n':

        case 'r':

        case 'u':

            return 4;

        case 'g':

        case 'k':

        case 'p':

            return 6;

        case 'f':

        case 'h':

            return 7;

        case 'b':

        case 's':

            return 8;

        default:

            return 5;

    }

}

int main(void){

    fastio();

    cin >>  input;

    int len = input.size(), flag=0, idx=0, curlen=0; 

    // len은 input의 길이, flag는 오류여부, idx는 검사하고있는 위치, curlen 검사한 길이

    while(idx<len){

        int lenOfword=lenOfchar(input[idx]);

        curlen+=lenOfword;

        if(len<curlen)

            flag=1;

        else{

            if(input[idx]=='a'){

                if(!(input[idx+1]=='e'&&input[idx+2]=='s'&&input[idx+3]=='p'&&input[idx+4]=='a'))

                    flag=1;

            }

            else if(input[idx]=='b'){

                if(!(input[idx+1]=='a'&&input[idx+2]=='e'&&input[idx+3]=='k'&&input[idx+4]=='j'&&input[idx+5]=='o'&&input[idx+6]=='o')&&input[idx+7]=='n')

                    flag=1;

            }

            else if(input[idx]=='c'){

                if(!(input[idx+1]=='a'&&input[idx+2]=='u'))

                    flag=1;

            }

            else if(input[idx]=='d'){

                if(!(input[idx+1]=='e'&&input[idx+2]=='b'&&input[idx+3]=='u'&&input[idx+4]=='g'))

                    flag=1;

            }

            else if(input[idx]=='e'){

                if(!(input[idx+1]=='d'&&input[idx+2]=='g'&&input[idx+3]=='e'))

                    flag=1;            

            }

            else if(input[idx]=='f'){

                if(!(input[idx+1]=='i'&&input[idx+2]=='r'&&input[idx+3]=='e'&&input[idx+4]=='f'&&input[idx+5]=='o'&&input[idx+6]=='x'))

                    flag=1;

            }

            else if(input[idx]=='g'){

            if(!(input[idx+1]=='o'&&input[idx+2]=='l'&&input[idx+3]=='a'&&input[idx+4]=='n'&&input[idx+5]=='g'))

                    flag=1;

            }

            else if(input[idx]=='h'){

                if(!(input[idx+1]=='a'&&input[idx+2]=='e'&&input[idx+3]=='g'&&input[idx+4]=='a'&&input[idx+5]=='n'&&input[idx+6]=='g'))

                    flag=1;

            }

            else if(input[idx]=='i'){

                if(!(input[idx+1]=='u'))

                    flag=1;

            }

            else if(input[idx]=='j'){

            if(!(input[idx+1]=='a'&&input[idx+2]=='v'&&input[idx+3]=='a'))

                    flag=1;    

            }

            else if(input[idx]=='k'){

                if(!(input[idx+1]=='o'&&input[idx+2]=='t'&&input[idx+3]=='l'&&input[idx+4]=='i'&&input[idx+5]=='n'))

                    flag=1;

            }

            else if(input[idx]=='l'){

                if(!(input[idx+1]=='o'&&input[idx+2]=='l'))

                    flag=1;

            }

            else if(input[idx]=='m'){

                if(!(input[idx+1]=='i'&&input[idx+2]=='p'&&input[idx+3]=='s'))

                    flag=1;    

            }

            else if(input[idx]=='n'){

                if(!(input[idx+1]=='u'&&input[idx+2]=='l'&&input[idx+3]=='l'))

                    flag=1;

            }

            else if(input[idx]=='o'){

                if(!(input[idx+1]=='s'))

                    flag=1;

            }

            else if(input[idx]=='p'){

                if(!(input[idx+1]=='y'&&input[idx+2]=='t'&&input[idx+3]=='h'&&input[idx+4]=='o'&&input[idx+5]=='n'))

                    flag=1;

            }

            else if(input[idx]=='q'){

                if(!(input[idx+1]=='u'&&input[idx+2]=='e'&&input[idx+3]=='r'&&input[idx+4]=='y'))

                    flag=1;

            }

            else if(input[idx]=='r'){

                if(!(input[idx+1]=='o'&&input[idx+2]=='k'&&input[idx+3]=='a'))

                    flag=1;

            }

            else if(input[idx]=='s'){

                if(!(input[idx+1]=='o'&&input[idx+2]=='l'&&input[idx+3]=='v'&&input[idx+4]=='e'&&input[idx+5]=='d'&&input[idx+6]=='a'&&input[idx+7]=='c'))

                    flag=1;

            }

            else if(input[idx]=='t'){

                if(!(input[idx+1]=='o'&&input[idx+2]=='d'))

                    flag=1;

            }

            else if(input[idx]=='v'){

                if(!(input[idx+1]=='i'&&input[idx+2]=='r'&&input[idx+3]=='u'&&input[idx+4]=='s'))

                    flag=1;

            }

            else if(input[idx]=='u'){

                if(!(input[idx+1]=='n'&&input[idx+2]=='i'&&input[idx+3]=='x'))

                    flag=1;    

            }

            else if(input[idx]=='w'){

                if(!(input[idx+1]=='h'&&input[idx+2]=='a'&&input[idx+3]=='l'&&input[idx+4]=='e'))

                    flag=1;

            }

            else if(input[idx]=='x'){

                if(!(input[idx+1]=='c'&&input[idx+2]=='o'&&input[idx+3]=='d'&&input[idx+4]=='e'))

                    flag=1;

            }

            else if(input[idx]=='y'){

                if(!(input[idx+1]=='a'&&input[idx+2]=='h'&&input[idx+3]=='o'&&input[idx+4]=='o'))

                    flag=1;

            }

            else{

                if(!(input[idx+1]=='e'&&input[idx+2]=='b'&&input[idx+3]=='r'&&input[idx+4]=='a'))

                    flag=1;

            }

        }

        if(flag)

            break;

        result.push_back(input[idx]);

        idx+=lenOfword;

    }

    if(flag)

        cout << "ERROR!" << '\n';

    else

        cout << "It's HG!"<< '\n'<<result <<'\n';

    return 0;

}