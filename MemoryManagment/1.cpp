#include<iostream>
#include<stack>

struct temp{
    int x,y;
    temp(){
        std::cout<<"Stucturing"<<"\n";
    }
    ~temp(){
        std::cout<<"Destuctring";
        std::cout<<"\n";
    };
};

void fun(){
    temp t;
    t.x = 10;
}

void gun(){
    temp * t = new temp;
    delete t;
}

int main(int argc,char const *args[]){
    fun();
    gun();
    int x = 10;
    std::cout<<x<<"\n";

    int* ptr = new int;
    std::cout<<*ptr<<"\n";
    *ptr=20;
    std::cout<<*ptr<<"\n";  

    {
        fun();
    }
    std::cout<<"Out of scope"<<"\n";
    
    int *arr = new int[2];
    arr[0] = 21;
    arr[1] = 22;
    std::cout<<arr[0]<<std::endl;
    delete [] arr;

    temp* trr = new temp[2];
    delete [] trr;

    int *arr1 = new int[5](); // initialize all value as 0
    std::cout<<arr1[2]<<std::endl;

    int **grid = new int*[5];
    for(int i=0; i<5 ;i++){
        grid[i] = new int[4];
    }
    std::cout<<grid<<std::endl;
    std::cout<<grid[0]<<std::endl;


    temp** sg = new temp*[2];
    for(int i=0; i<2 ;i++){
        sg[i] = new temp[2];
    }

    for(int i=0;i<2;i++){
        delete [] sg[i];
    }

    delete [] sg;
    //malloc return memory block but type is not defined 
    //so we are defining it to int type by (int*)
    
    int *m = (int*) malloc(4);   //return void* pointer
    free(m); // for free memory of m
    
    int *t = new int;free(t);
    free(t);
    return 0;
}