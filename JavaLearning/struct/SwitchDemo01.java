package com.kuang.struct;

public class SwitchDemo01 {
    public static void main(String[] args) {
        //case 穿透
        char grade = 'C';
        switch (grade){
            case 'A':
                System.out.println("优秀");
                break;  //可选
            case 'B':
                System.out.println("良好");
                break;
            case 'C':
                System.out.println("及格");
                break;
            case 'D':
                System.out.println("再接再厉");
                break;
            case 'E':
                System.out.println("挂科");
                break;
            default:
                System.out.println("未知等级");
        }
    }
}
