#pragma once

class function{
public:
    function(double (*ptr)(double x)){
        func_ptr = ptr;
    }
    function(){
        
    }
    double operator()(double x){
        return func_ptr(x);
    }
private:
    double (*func_ptr)(double x);
};