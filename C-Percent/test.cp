<<<<<<< HEAD
struct person{
   int age;
   string name;
   char sex;
   float money;
   struct person* parent;
};
=======
int fac(int n){
    if n == 1 {return n;}
    else {return (n * fac(n - 1));} 
}

>>>>>>> 765bc0d59c38fc228706d60b97e1898f81f5fab6
int main(){
    int m, result;
    
    m = read();
    write(m);
    
    if m > 1 {result = fac(m);}
    else {result = 1;}

    write(result);

    return 0;
}