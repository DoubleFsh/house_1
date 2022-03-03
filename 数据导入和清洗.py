import numpy as np
import pandas as pd
import matplotlib as mpl
import matplotlib.pyplot as plt

'''
===数据导入===
'''

#从excel导入数据
df = pd.read_excel('stu_data1.xlsx')
print(df.shape)

'''
===数据清洗===
'''

#将重复的数据进行删除drop_duplicates()
df0 = df.drop_duplicates()
print(df0.shape)
#显示被删除的数据
print("删除重复的数据如下:")
print(df[df.duplicated()])


#复制一份数据
df1=df0.copy()
#显示所有数据
print(df1)
print(df1.shape)
#显示所有列数据的数据类型
cols = df1.columns
for col in cols:
    print(col+' : '+ str(df1[col].dtype))

'''
学号 : int64
班级 : int64
姓名 : object
性别 : object
英语 : int64
体育 : object
军训 : object
数分 : int64
高代 : int64
解几 : int64
'''
#对体育数据进行数据清洗，将所有文字类型的数据转换成0
ty = list(df1.体育)
j=0
for i in ty:
    if type(i)!=int:
        ty[j]=0
    j=j+1
df1['体育'] = ty
print(df1.体育)

#显示所有列数据的数据类型
cols = df1.columns
for col in cols:
    print(col+' : '+ str(df1[col].dtype))
    
#对军训数据进行数据清洗，将所有文字类型或空的数据转换成0
ty = list(df1.军训)
j=0
for i in ty:
    if type(i)!=int:
        ty[j]=0
    j=j+1
df1['军训'] = ty
print(df1.军训)

#显示哪列数据存在空值
#print(df1.isnull().sum())

#print(df1)

#数据总分统计及合并到原数据表中
df2 = df1.copy()
print(df2.shape)
df2['score'] = df2.英语 + df2.体育 + df2.军训 + df2.数分 + df2.高代 + df2.解几
print(df2.score.describe())
print(df2)

'''
===数据分割===
'''

#对合并后的数据表的总分进行分组区域划分
#区域划分区间设定
bins = [df2.score.min()-1,400,450,df2.score.max()+1]
#设定区域的标签名称
label = ["一般","较好","优秀"]
#进行数据分割
df3 = pd.cut(df2.score,bins,right=False,labels=label)
'''
1 x：被分割的数组数据，可以是df[col]，np.array，还可以是pd.seres，list 但是数据必须是一维的
2 bins：被分割后的区间，有三种形式，int值（如bins=5，就是将x平均分为5位），list或者np.array（如bins=[1,2,3]，则将x按照(1,2],(2,3]分割），pandas.IntervalIndex 定义要使用的精确区间
3 right：bool型参数，默认为True，表示是否包含区间右部
4 labels：给分割后的区间打标签，但是labels的长度必须和分割后的区间的长度相等
5 retbins：bool型的参数，表示是否将分割后的bins返回
6 precision：保留区间小数点的位数，默认为3
7 include_lowest：bool型的参数，表示区间的左边是开还是闭的，默认为false，也就是不包含区间左部（闭）
8 duplicates：是否允许重复区间
'''
#把切割好的标签内容合并到df2表中
df2['类别']= df3
print(df2)


dflist=[0,0,0]
lb = list(df2.类别)
for i in lb:
    if i=='一般':
        dflist[0]=dflist[0]+1
    elif i=='较好':
        dflist[1]=dflist[1]+1
    else:
        dflist[2]=dflist[2]+1


#绘制图形展示不同类别的数据占比
'''  
label1=['一般','较好','优秀']
fig = plt.figure()
sub = fig.add_subplot(111)
sub.pie(dflist, labels=label1, shadow=True,explode=[0.1,0.1,0.1],autopct="%1.1f%%")
sub.legend(bbox_to_anchor=(1.2,0.8))
plt.show()
'''
#设置字体样式
mpl.rcParams['font.family']='sans-serif'
mpl.rcParams['font.sans-serif']=[u'SimHei']
title = '学生成绩占比图'
fig = plt.figure(title, figsize=(8, 7))
fig.tight_layout()
ax = fig.add_subplot(111)
labels = ['一般','较好','优秀']
ax.pie(dflist, labels= labels, #radius=0.8, #data 是数据，labels 是标签，radius 是饼图半径
       explode=[0.1,0.1,0.1], #explodes 为0 代表不偏离圆心， 不为零则代表偏离圆心的距离
       autopct='%1.1f%%') #显示所占比例，百分数
plt.legend( loc = 'upper right',bbox_to_anchor=(1.1, 1.05), fontsize=14, borderaxespad=0.3)
plt.suptitle(title, fontsize=20)
plt.show()
# plt.close()
plt.savefig('bingtu.png',dpi=120,bbox_inches='tight')


