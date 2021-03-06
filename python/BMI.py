'''Practice 1: BMI calculation

The Body Mass Index (BMI) is defined as the weight (kg) divided by the height (m) of the square;

For example, a person is 1.75 meters tall, weighs 75 kilograms, and has a BMI of 24.49.

The domestic and international BMI indicators are shown below:

Complete the procedure as required:

Write three functions to calculate the value of BMI, the recommended value of international BMI indicator, and the recommended value of domestic BMI indicator;
Combined with abnormal processing, the BMI value is calculated and output according to the weight and height input by the user, and the recommended values of the international and domestic BMI indicators are simultaneously output;'''


def computeBMI(height,weight):
    """compute BMI value based on height and weight"""
    BMI = weight/(height**2)
    return BMI


def internationalBMI(BMI):
    """return international BMI index, the input parameter is BMI value"""
    if BMI < 18.5:
        nat = "偏瘦"
    elif 18.5 <= BMI < 25:
        nat = "正常"
    elif 25 <= BMI < 30:
        nat = "偏胖"
    else:
        nat = "肥胖"
    print(nat)
    return nat


def domesticBMI(BMI):
    """return domestic BMI index, the input parameter is BMI value"""
    if BMI < 18.5:
        who = "偏瘦"
    elif 18.5 <= BMI < 24:
        who = "正常"
    elif 24 <= BMI < 28:
        who = "偏胖"
    else:
        who = "肥胖"
    return who 


height,weight = eval(input("请输入身高(米)，体重(公斤)："))
try:
    BMI = computeBMI(height,weight)
except:
    print("输入错误")
else:
    print("国际：{}，国内：{}".format(internationalBMI(BMI),domesticBMI(BMI)))


#another method
def international_domesicBMI(height,weight):
    bmi = weight / pow(height,2)
    print("BMI 数值为:{:.2f}".format(bmi))
    who,nat = "",""
    if bmi < 18.5:
        who,nat = "偏瘦","偏瘦"
    elif 18.5 <= bmi < 24:
        who,nat = "正常","正常"
    elif 24 <= bmi < 25:
        who,nat = "正常","偏胖"
    elif 25 <= bmi < 28:
        who,nat = "偏胖","偏胖"
    elif 28 <= bmi < 30:
        who,nat = "偏胖","肥胖"
    else:
        who,nat = "肥胖","肥胖"
    return who,nat

height,weight = eval(input("请输入身高(米)和体重(公斤)[用逗号隔开]:"))
who,nat = international_domesicBMI(height,weight)
print("BMI指标为;国际'{0},国内'{1}".format(who,nat))





