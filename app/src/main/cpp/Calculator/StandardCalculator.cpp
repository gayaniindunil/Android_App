//
// Created by GC2176 on 1/27/2021.
//

#include "StandardCalculator.h"

StandardCalculator::StandardCalculator() {}

StandardCalculator::~StandardCalculator() {
}

bool StandardCalculator::isOperator( const std::string& token)
{
    return token == "+" || token == "-" || token == "%" || token == "*" || token == "/";
}

string StandardCalculator::validate(string input) {
    // check 1/0 division
    if (std::regex_match ("1+1/0+ 3", std::regex("(1)(\\/)(0)") ))
    {
        return "cannot divide by zero";
    }// check 0/0 division
    else if (std::regex_match ("1+1/0+ 3", std::regex("(1)(\\/)(0)") ))
    {
        return "answer undefined";
    } // multiply by 0
    // else if (std::regex_match ("1+1/0+ 3", std::regex("(1)(\\/)(0)") )) || std::regex_match ("1+1/0+ 3", std::regex("(1)(\\/)(0)") ) )
    // {
    //         return "0";
    // }
    return "true";
}

vector<string> StandardCalculator::tokenize(string inputs)
{
    vector<string> tokens;
    string str = "";

    for (int i = 0; i < (int) inputs.length(); i++)
    {
        const std::string token( 1, inputs[ i ] );
        if (!token.empty())
        {
            tokens.push_back(token);
        }

    }
    return tokens;
}

vector<string> StandardCalculator::tokenize1(string inputs)
{
    vector<string> tokens;
    string str = "";
    std::stack<string>  temp;

    for (int i = 0; i < (int) inputs.length(); i++)
    {
      const std::string token( 1, inputs[ i ] );
      if (! isOperator(token) ){
          temp.push(token);
      } else{
          while (!temp.empty()){
              str = temp.top() + str ;
              temp.pop();
          }
          tokens.push_back(str);
          tokens.push_back(token);
          str = "";
      }
    }
    if ( !temp.empty() ){
        while (!temp.empty()){
            str =  str+ temp.top() ;
            temp.pop();
        }
        tokens.push_back(str);
    }
    return tokens;
}


std::queue<std::string> StandardCalculator::getPostfixExpression(std::vector<std::string> tokens){

    std::queue<std::string> postfix_expression;
    std::stack <string> operators;
    string *operatorE;

    for (int i = 0; i < tokens.size(); i++)
    {
        const std::string tokenE = tokens[ i ];

        if (isOperator(tokenE))
        {
            if (operators.empty())
            {
                operators.push(tokenE);
            }
            else // error if the operator is invalid operator not a digit
            {
                *operatorE = operators.top();
                operators.pop();
                postfix_expression.push(*operatorE);
                operators.push(tokenE);
            }
        }
        else{
            postfix_expression.push(tokenE);
        }

    }
    if ( !operators.empty() ){
        *operatorE = operators.top();
        operators.pop();
        postfix_expression.push(*operatorE);
    }

    return postfix_expression;
}

double StandardCalculator::calOperatorTemp(double a, double b, string oper){
    if (oper == "+"){
        return a+b;
//        return Addition<double >(a,b);
    }
    else if (oper == "-"){
        return a-b;
//        return Subtraction(a,b);
    }else if (oper == "*"){
        return a*b;
//        return Multiplication(a,b);
    }else if (oper == "/"){
        return a/b;
//        return Division(a,b);
    }else if (oper == "%"){
//        return Percent(a,b);
    }



}

double StandardCalculator::postfixExpToDouble(queue<string> *postFixExp, int expressionLength){
    stack<string> st;
    double result =  0.0;

    for ( int i = 0; i < expressionLength; ++i ){
        string token = postFixExp->front();
        postFixExp->pop();

        if ( !isOperator(token) ){
            st.push(token);
        }
        else {
            string val2 = st.top();
            st.pop();
            double d2 = strtod( val2.c_str(), NULL );

            if ( !st.empty() ){
                string val1 = st.top();
                st.pop();
                double d1 = strtod( val1.c_str(), NULL );

                //Get the result
                result = calOperatorTemp(d1,d2,token);
            }
//            else{
//                if ( token == "-" )
//                    result = d2 * -1;
//                else
//                    result = d2;
//            }

            // Push result onto stack
            std::ostringstream s;
            s << result;
            st.push( s.str() );
        }
    }
//    return strtod( st.top().c_str(), NULL );
    return result;
}

string StandardCalculator::calculate(string input_expression) {
//    string s = getInputExpression();
    vector<string> tokens = tokenize1(input_expression);
    queue<string> postfix_expression = getPostfixExpression(tokens);
    double Ans = postfixExpToDouble(&postfix_expression, postfix_expression.size() );

    return to_string(Ans);
}

