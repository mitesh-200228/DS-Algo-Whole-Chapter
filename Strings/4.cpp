//Why String are immutable in java ?
// Immutable Object means when your stored value objects CAN'T be cahnged

// E.X.

// public static void main(String[] args){
//     String str1 = "Value1";
//     str1 = "Value2";


//     you think that value will change , but it is not
//     so what happenes ????
//     Reference to the old value will be removed and created new reference to the new value
//     So , basically we create new value 


//     Old value will collected by JGC

//     we use new so that we get new object that point to different value , so no need to use new keyword

// }