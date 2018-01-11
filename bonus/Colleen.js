/*
    comment
*/
let other_func = (a) => console.log(a);
!function main() {
    /*
        comment2
    */
    other_func("/*\n    comment\n*/\nlet other_func = (a) => console.log(a);\n!" + main + "()");}()
