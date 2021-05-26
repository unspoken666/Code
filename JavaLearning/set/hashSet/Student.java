package com.set.hashSet;

/*
总结：
1.存入HashSet中的元素必须实现hashCode和 equals方法
2.元素的 hashCode一样，经过 y=k(x)散列出来的位置一定一样
  元素的 hashCode不一样，经过 y=k(x)散列出来的位置有可能一样
3.散列函数多半是hashCode%空间长度
 */
public class Student {
    private String id;
    private String name;
    private int age;

    @Override
    public int hashCode(){
        final int prime = 31;
        int result = 1;
        result = prime * result + age;
        result = prime * result +((id == null)? 0 : id.hashCode());
        result = prime * result +((name == null)? 0 : name.hashCode());
        return result;
    }

    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;

        if(obj == null)
            return false;

        if(getClass() != obj.getClass())
            return false;

        Student other = (Student) obj;
        if(age != other.age)
            return false;
        if(id == null){
            if(other.id != null)
                return false;
        }else if(!id.equals(other.id))
            return false;

        if(name == null){
            if(other.name != null)
                return false;
        }else if(!name.equals(other.name))
            return false;
        return true;

    }

    @Override
    public String toString(){
        return "Student [id=" + id + ",name=" + name + ",age=" + age + "]";
    }
}
