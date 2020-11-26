#include<iostream>
#include<math.h>
#include<stdexcpt.h>

using namespace std;

class calc
{
private:
    int len,
        intPartTemp,
        intLen,
        floatLen,
        ten,
        str;

    double value,
        floatPartTemp,
        x; 

    char ch[1000] ;
    char carriage[100];
    char copy [1000];
    void setInfo()
{
    cin.getline(copy,1000);
    copyArray(copy, ch);
    replace(x,'x');
}

void copyArray (char main [], char copy [] )
{
    int len = strlen(main);
    int temp;
    for(temp=0;temp<=len;temp++)
    {
        copy[temp] = main[temp];
    }
}
void edit()
{
    int temp;
    len = strlen(ch);
    for(temp=0;temp<len;temp++)
    {
         if(!triangleMove(temp) && isalpha(ch[temp]) && isalpha(ch[temp+1]) )
            insert(temp,len,'*');
        else if(temp!=0 && isalpha(ch[temp]) && isdigit(ch[temp-1]))
            insert(temp,len,'*');
        else if(temp!=0 && ch[temp] == '(' && ch[temp-1] ==')' )
            insert(temp,len,'*');
        else if(temp!=0 && ch[temp] == '(' && isdigit(ch[temp-1]) )
        insert(temp,len,'*');
        else if( ( ch[temp]=='.' && temp == 0) || ( temp>0 && ch[temp] == '.' && !isdigit( (ch[temp-1]) ) ) )
            insert(temp,len,'0');
        else if( ch[temp] == '+' && ch[temp+1] =='+' )
            smaller(temp,len,'+');
        else if( ch[temp] == '+' && ch[temp+1] =='-' )
            smaller(temp,len,'-');
        else if( ch[temp] == '-' && ch[temp+1] =='-' )
            smaller(temp,len,'+');
        else if( ch[temp] == '-' && ch[temp+1] =='+' )
            smaller(temp,len,'-');

    }
    if(ch[0]=='+')
        decrease(0,1);

}

bool exam ()
{
    int leftBracket=0,
        rightBracket=0,
        len = strlen(ch), 
        temp;

    for(temp = 0; temp<len; temp++)
    {
        if( isdigit(ch[temp]) )
            continue;
        else if(ch[temp] == '(')
            leftBracket ++;
        else if(ch[temp] == ')')
            rightBracket ++;
        else if( !isalpha(ch[temp]) && !isalpha(ch[temp+1]) && !isdigit(ch[temp+1]) )
            return false;

    }
    if(rightBracket != rightBracket)
        return false;
    if( !isdigit (ch[len-1] ) && ch[len-1] != ')'  )
        return false;
    return true;
}

bool triangleMove(int &temp)
{

    if(ch[temp] == 's' && ch[temp+1] == 'i' && ch[temp+2] == 'n' && ch[temp+3] == '(' && isdigit(ch[temp+4]) )
    {
        temp+=4;
        return true;
    }

    else if(ch[temp] == 'c' && ch[temp+1] == 'o' && ch[temp+2] == 's' && ch[temp+3] == '(' && isdigit(ch[temp+4]) )
    {
        temp+=4;
        return true;
    }

    else if(ch[temp] == 't' && ch[temp+1] == 'a' && ch[temp+2] == 'n' && ch[temp+3] == '(' && isdigit(ch[temp+4]) )
    {
        temp+=4;
        return true;
    }

    return false;
}

bool triangle (int temp)
{

    if(ch[temp] == 's' && ch[temp+1] == 'i' && ch[temp+2] == 'n' && ch[temp+3] == '(' && isdigit(ch[temp+4]) )
    {
        return true;
    }

    else if(ch[temp] == 'c' && ch[temp+1] == 'o' && ch[temp+2] == 's' && ch[temp+3] == '(' && isdigit(ch[temp+4]) )
    {
        return true;
    }

    else if(ch[temp] == 't' && ch[temp+1] == 'a' && ch[temp+2] == 'n' && ch[temp+3] == '(' && isdigit(ch[temp+4]) )
    {
        return true;
    }

    return false;
}

void increase (int order,  int &len, int count)
{
    int temp, temp2;

    for(temp2=0; temp2<count; temp2++)
{
    len++;

    for(temp=len;temp>order;temp--)
    {
        ch[temp]=ch[temp-1];
    }
}
}

void decrease (int order, int count)
{
    int temp, temp2;
    int len = strlen(ch);
    for(temp2=0;temp2<count;temp2++)
{

    for(temp=order;temp<len;temp++)
    {
        ch[temp]=ch[temp+1];
    }
    len--;
}
}

void insert(int order,  int &len, char ob)
{

    increase (order, len,1);
    ch[order] = ob;

}

void smaller(int order,  int &len, char ob)
{
    decrease(order, 1);
    ch[order] = ob;
}

int getNumLen(double num)
{

    int intPart,
        temp, 
        numLen;

    bool plus = false;

    double floatPart;

    if(num<0)
    {
        plus = true;
        num*=-1;
    }

    intPart = intPartTemp = static_cast<int>(num);
    floatPart = floatPartTemp = num - intPart;

    for(intLen=0;intPart>0;intPart/=10)
    {
        intLen++;
    }

    if(intLen == 0)
        intLen = 1;

    floatPart>0?floatLen=1:floatLen=0;
    for(temp= 1; floatPart!=0 && floatLen<10 ; floatLen++)
    {
        floatPart*=10;
        temp = static_cast<int>(floatPart) ;
        floatPart-=temp;
    }

    if(plus){
        intLen++;
        intPart *=-1;
    }
    numLen = intLen + floatLen;



    return numLen;
}

void convert(char carriage[], double num, int intLen, int intPart, int floatLen, double floatPart, int numLen, bool sign )
{
    int temp1, temp;
    int start = 0;

        if(numLen>0)
        {
            carriage[numLen]=0;
        }
        else
        {
            numLen=1;
            carriage[numLen]=0;
        }

    if(!sign){
        start ++;
        carriage[0] = '-';
    }

    for(temp=intLen-1;temp>=start;temp--)
    {
        temp1= intPart % 10 ;
        carriage[temp]= temp1+48;

        intPart/=10; 
    }

    if(floatPart!=0){

        carriage[intLen]='.';
        carriage[intLen + floatLen ]=0;

    for(temp=intLen+1;temp<floatLen+intLen; temp++)
    {
        floatPart*=10;
        temp1 = floatPart;
        carriage[temp]=temp1+48;
        floatPart-=temp1;
    }

    }

}

void replace ( double num, char var)
{
    int len = strlen(ch);
    int temp;

    for(temp=0;temp<len;temp++)
    {
        if(ch[temp]==var)
        {
            decrease(temp,1);
            insertNum(temp,  num);
        }
    }
}

double getFloatNum (int &position, int count)
{

    double num;

    int temp;
    int arrange;

    ten = 10;
    num = 0;
    arrange=1;

    for(temp=0; isdigit(ch[position]) && temp<count; temp++)
    {

        num = num + (ch[position++]-48)/pow(ten,static_cast<double>(arrange++));
    }

    position--;

return num;
}


double getNum (int &position)
{

    double num,
            floatPart; 

    double sign = 1;

    ten = 10;
    num = 0;

    if(ch[position]=='-')
        position++;

    if( (position>0 && ch[position-1] == '-') || (position==0 &&ch[position] =='-') )
    {
        sign = false;
    }

    while(isdigit(ch[position]))
    {
        num = num *10 + ch[position]-48;
        position++;
    }
    position--;

    if(ch[position+1]=='.')
    {
        position+=2;
        floatPart = getFloatNum(position, 5);

        num = num + floatPart ;
    }

    if(!sign)
        num*=-1;

    return num;
}

bool check(int temp, double &num1 , double &num2, char &symbol)
{

    int len1,
        len2;

    num1 = getNum(temp);
    len1 = getNumLen(num1);

    while(isdigit(ch[temp]))
    temp++;

    temp--;

    if(ch[temp+1]!=0 && !isdigit(ch[temp+1]) )
    {

    symbol = ch[++temp];

    num2 = getNum (++temp);
    len2 = getNumLen (num2);


    return true;
    }

    else
        return false;
}

void trigon_op(int &temp)
{

    double num,
            insNum;

    int numLen;
        len = strlen(ch);

    if(ch[temp]=='s' && ch[temp+1] =='i' && ch[temp+2] =='n')
    {

        temp+=4;

        insNum = getNum(temp);

        numLen= getNumLen(insNum);

        temp-=3+numLen;

        decrease(temp,numLen+5);

        num=sin(insNum);

        insertNum(temp, num);
        temp+=getNumLen(num);
    }

    else if(ch[temp]=='c' && ch[temp+1] =='o' && ch[temp+2] =='s')
    {

        temp+=4;

        insNum = getNum(temp);

        numLen= getNumLen(insNum);

        temp-=3+numLen;

        decrease(temp,numLen+5);

        num=cos(insNum);

        insertNum(temp, num);

    }

    else if(ch[temp]=='t' && ch[temp+1] =='a' && ch[temp+2] =='n')
    {

        temp+=4;

        insNum = getNum(temp);

        numLen= getNumLen(insNum);

        temp-=3+numLen;

        decrease(temp,numLen+5);

        num=tan(insNum);

        insertNum(temp, num);
    }
}

void getBorders(int &str, int &end)
{
    int len = strlen(ch) -1 ;
    int temp;
    str=0;
    end = len;

    for(temp=0;temp<len;temp++)
    {

    if(temp>0 && ch[temp]=='(' && !isalpha(ch[temp-1]) )
        str=temp+1;

    else if(str > 0 && ch[temp]== ')' && !isalpha(ch[str-1]) )
    {
        end = temp;
        break;
    }

}



}

void process (double num1, double num2, char symbol, int temp)
{
    int len1 = getNumLen(num1),
         len2 = getNumLen(num2),
        len = strlen(ch);
        int count;

    double num; 

    if(symbol == '^')
        num = pow(num1,num2);

    else if(symbol == '*')
        num = num1*num2;

    else if(symbol == '/')
        num = num1/num2;

    else if(symbol == '+')
        num = num1+num2;

    else if(symbol == '-')
        num = num1+num2;

    if(num2 >= 0 && num1 >=0)
        count = len1+len2;
    else if(num2 >= 0 && num1 <0)
        count = len1+len2;

    else if(num2 < 0 && num1 >=0)
        count = len1 + len2;

  
    else if(num2 < 0 && num1 <0)
    {
        count = len1 + len2 ;
        temp--;
    }
    if(symbol != '-')
        count ++ ;
    decrease(temp,count);


    insertNum(temp,num);
        edit();
}

void semiMath(int str, int end, char ch[])
{
    int temp,
        zero = 0;

    char symbol;

    double num1,
            num2;

    len = end;



    for(temp=str;temp<len;temp++)
    {
        if(triangle(temp))
        {
            trigon_op(temp);
            getBorders(str,end);
            temp = str -1;
            len=end+1;
        }
    }
 
    len = end;
    for(temp=str;temp<len;temp++)
    {

            if( (isdigit(ch[temp]) || ch[temp]=='-' ) && check(temp, num1, num2, symbol) )
            {
                if(symbol == '^')
                {
                    process(num1,num2,symbol,temp);
                    getBorders(str,end);
                    temp = str -1;
                    len=end+1;}
            }
    }


    len = end;
    symbol = 0;
    for(temp=str;temp<len;temp++)
    {

            if( (isdigit(ch[temp]) || ch[temp]=='-' ) && check(temp, num1, num2, symbol) )
            {
                if(symbol == '*' || symbol == '/')
                {
                    process(num1,num2,symbol,temp);
                    getBorders(str,end);
                    temp = str -1;
                    len=end;
                }
            }
    }


    len = end;
    symbol = 0;
    for(temp=str;temp<len;temp++)
    {

            if( (isdigit(ch[temp]) || ch[temp]=='-' ) && check(temp, num1, num2, symbol) )
            {
                if(symbol == '+' || symbol == '-')
                {
                    process(num1,num2,symbol,temp);
                    getBorders(str,end);
                    temp = str -1;
                    len=end;
                }
            }
    }

}

double math (char ch[], double x)
{
    int len = strlen(ch) ,
        temp, 
        zero = 0,
        end ;

    double  num;

    edit();


 
if(exam())
{
for(temp = 0; temp <len; temp++)
{
    getBorders(str,end);

    semiMath(str, end,ch);

    len = strlen(ch);

   
    if(str !=0)
    {
        getBorders(str,end);

        decrease(str-1,1);
        decrease(end-1 ,1);
        

    }
}

    num=getNum(zero);

    return num;
}

else
    throw invalid_argument(
    "Your formula is out of mathimatics rules");

}

void insertNum(int order, double num)
{
    int temp, numLen;
    int len;
     numLen = getNumLen(num);
    bool sign;

     len = strlen(ch);

     if(num>=0)
         sign = true;
     else
         sign = false;

    convert(carriage,num,intLen,intPartTemp,floatLen,floatPartTemp, numLen, sign);

    for(temp = numLen-1; temp>=0 ; temp--)
    {

        increase(order, len,1);
        ch[order] = carriage [temp];
    }

}

public:

double getResult()
{
    setInfo();
    double num = math(ch,value);
    return num;
}

double getResult(char ch[], double value)
{
    double num = math(ch,value);
    return num;
}

};

void main ()
{

    calc test;
    while(cout<<"= "<<test.getResult()<<endl<<endl<<endl);

}