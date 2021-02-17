//
// Created by GC2176 on 1/27/2021.
//

#include "ScientificCalculator.h"

const int LEFT_ASSOC  = 0;
const int RIGHT_ASSOC = 1;

// Map the different operators: +, -, *, / etc
typedef std::map< std::string, std::pair< int,int >> OpMap;

const OpMap::value_type assocs[] =
        {  OpMap::value_type( "+", std::make_pair( 0, LEFT_ASSOC ) ),
           OpMap::value_type( "-", std::make_pair( 0, LEFT_ASSOC ) ),
           OpMap::value_type( "*", std::make_pair( 5, LEFT_ASSOC ) ),
           OpMap::value_type( "/", std::make_pair( 5, LEFT_ASSOC ) ) };

const OpMap opmap( assocs, assocs + sizeof( assocs ) / sizeof( assocs[ 0 ] ) );

ScientificCalculator::ScientificCalculator() {}

ScientificCalculator::~ScientificCalculator() {
}

string ScientificCalculator::validate(string input) {
    return string();
}

bool ScientificCalculator::isParenthesis( const string& token){
    return token == "(" || token == ")";
}


bool ScientificCalculator::isOperator( const string& token){
    return token == "+" || token == "-" ||  token == "*" || token == "/" || token == "%" ||
           token == "^" || token == "sqrt" || token == "log" ||
           token == "sin" || token == "cos" ||token == "tan" ;
}

bool ScientificCalculator::isAssociative( const string& token, const int& type){
    const std::pair<int,int> p = opmap.find( token )->second;
    return p.second == type;
}

int ScientificCalculator::cmpPrecedence( const string& token1, const string& token2 )
{
    const std::pair<int,int> p1 = opmap.find( token1 )->second;
    const std::pair<int,int> p2 = opmap.find( token2 )->second;

    return p1.first - p2.first;
}

bool ScientificCalculator::getPostfixExpression( const vector<string>& inputTokens,const int& size,vector<string>&postFixVector )
{
    bool success = true;
    list<string> out;
    stack<string> stack;

    for ( int i = 0; i < size; i++ )
    {
        const string token = inputTokens[i];

        if ( isOperator( token ) )
        {
            const string o1 = token;

            if ( !stack.empty() )
            {
                string o2 = stack.top();

                while ( isOperator( o2 ) &&
                        ( ( isAssociative( o1, LEFT_ASSOC ) &&  cmpPrecedence( o1, o2 ) == 0 ) ||
                          ( cmpPrecedence( o1, o2 ) < 0 ) ) )
                {

                    stack.pop();
                    out.push_back( o2 );

                    if ( !stack.empty() )
                        o2 = stack.top();
                    else
                        break;
                }
            }
            stack.push( o1 );
        }

        else if ( token == "(" )
        {
            stack.push( token );
        }

        else if ( token == ")" )
        {
            string topToken  = stack.top();

            while ( topToken != "(" )
            {
                out.push_back(topToken );
                stack.pop();

                if ( stack.empty() ) break;
                topToken = stack.top();
            }

            if ( !stack.empty() ) stack.pop();

            if ( topToken != "(" )
            {
                return false;
            }
        }
        else
        {
            out.push_back( token );
        }
    }

    while ( !stack.empty() )
    {
        const string stackToken = stack.top();

        if ( isParenthesis( stackToken )   )
        {
            return false;
        }
        out.push_back( stackToken );
        stack.pop();
    }
    postFixVector.assign(out.begin(), out.end());

    return success;
}


double ScientificCalculator::postfixExpToDouble( std::vector<std::string> *tokens ,int tokenVectorLength)
{
    std::stack<std::string> st;
    double result =  0.0;

    for ( int i = 0; i < tokenVectorLength; ++i )
    {
        string token = tokens->at(i);
        if ( !isOperator(token) )
        {
            st.push(token);
        }
        else
        {
            const string val2 = st.top();
            st.pop();
            const double d2 = strtod( val2.c_str(), NULL );

            if ( !st.empty() )
            {
                const string val1 = st.top();
                st.pop();
                const double d1 = strtod( val1.c_str(), NULL );

                //Get the result
                result = calOperatorTemp(d1,d2,token);
            }
            else
            {
//                if ( token == "-" )
//                    result = d2 * -1;
//                else
//                    result = d2;
            }

            std::ostringstream s;
            s << result;
            st.push( s.str() );
        }
    }

    return strtod( st.top().c_str(), NULL );
}

double ScientificCalculator::calOperatorTemp(double a, double b, string oper){
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
    else if(oper == "^"){
        return pow(a,b);
    }
    else if(oper == "sin"){
        return sin(a);
    }
    else if(oper == "cos"){
        return cos(a);
    }
    else if(oper == "tan"){
        return tan(a);
    }
    else if(oper == "log"){
        return log(a);
    }
    else if(oper == "sqrt"){
        return sqrt(a);
    }

}

vector<string> ScientificCalculator::tokenize( string expression )
{
    vector<string> tokens;
    string str = "";

    for ( int i = 0; i < (int) expression.length(); ++i )
    {
        const std::string token( 1, expression[ i ] );

        if ( isOperator( token ) || isParenthesis( token ) )
        {
            if ( !str.empty() )
            {
                tokens.push_back( str ) ;
            }
            str = "";
            tokens.push_back( token );
        }
        else
        {
            // Append the numbers
            if ( !token.empty() && token != " " )
            {
                str.append( token );
            }
            else
            {
                if ( str != "" )
                {
                    tokens.push_back( str );
                    str = "";
                }
            }
        }
    }
    if ( !str.empty() )
    {
        tokens.push_back( str ) ;
    }

    return tokens;
}


string ScientificCalculator::calculate(string input_expression) {

//    vector<string> ss = tokenize("3+4*8+34/5");
    vector<string> ss = tokenize(input_expression);
    vector<string> postfix_expression;
    bool pfexpValid = getPostfixExpression(ss,ss.size(), postfix_expression);
    double Ans = postfixExpToDouble(&postfix_expression, postfix_expression.size() );

    if (pfexpValid){
        return to_string(Ans);
    } else{
        return "Invalid Expression";
    }

}
