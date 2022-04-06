#include<iostream>
using namespace std;
#include<string>
#include<stack>

bool IsOperator(char s) {
    if (s == '*' || s == '/' || s == '-' || s == '+' )
        return true;


    return false;




}
bool IsOperand(char C)
{
    if (C >= '0' && C <= '9')
        return true;
    if (C >= 'a' && C <= 'z')
        return true;
    if (C >= 'A' && C <= 'Z')
        return true;

    return false;
}

//func to check the precedence
int check_precedenc(char s) {
    if (s == '^')
        return 3;
    else if (s == '/' || s == '*')
        return 2;
    else if (s == '+' || s == '-')
        return 1;

    return -1;
}
//function to transform from infix to post fix
string infix_to_postfix(string expression) {
    stack<char> S;
    string postfix;
    int len=expression.length();
    for ( int i = 0; i < len; i++) {




        if (IsOperator(expression[i]))

        {
            while (!S.empty() && S.top() != '(' &&check_precedenc(expression[i])<=check_precedenc(S.top()))
            {

                postfix += S.top();
                S.pop();
            }
            S.push(expression[i]);
        }

        else if (IsOperand(expression[i]))
        {
            postfix += expression[i];
        }

        else if (expression[i] == '(')
        {
            S.push(expression[i]);
        }

        else if (expression[i] == ')')
        {
            while (!S.empty() && S.top() != '(') {
                postfix += S.top();
                S.pop();
            }
            //to remove the open bracket(
            S.pop();
        }


    }
    while (!S.empty()) {
        postfix += S.top();
        S.pop();
    }

    return postfix;
}

int calculate_operation(float first,float second, char s){
    if(s=='/'){

        return first/second;
    }
    if(s=='*'){

        return first*second;
    }
    if(s=='+'){

        return first+second;
    }
    if(s=='-'){

        return first-second;
    }
    else
        return 0;



}
void evaluate_postfix(string postfix){
    stack<float> st;
    for(int i=0;i<postfix.size();i++){

        if(IsOperator(postfix[i])){

            float  first;
            float second;
            float res;
            first=st.top();
            st.pop();
            second=st.top();
            st.pop();
            res=calculate_operation(first,second,postfix[i]);
            st.push(res);



        }
        else if(IsOperand(postfix[i])){

            st.push(postfix[i]-'0');



        }




    }
    cout<<st.top();
}


int main() {
    string expression;
       cout<<"            welcome to equation solver"<<endl;
    cout<<"Enter the infix expression"<<endl;
    cin>>expression;
    cout<<"the postfix expression is  "<<infix_to_postfix(expression)<<endl;
    string evaluate;
    cout<<"Enter the expression to evaluate"<<endl;
    cin>>evaluate;
    cout<<"after evaluate the result is  ";
    evaluate_postfix(evaluate);

    return 0;
}
