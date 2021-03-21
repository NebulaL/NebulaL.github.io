import os
from urllib import parse
from urllib import request

def get_filep(path,extension_name):
    a=[]
    for filepath,dirnames,filenames in os.walk(path):
        for filename in filenames:
            string=os.path.join(filepath,filename)
            if extension_name in string:
                a.append(string)
                #print(string)
    return a
# 获取一个目录下所有指定扩展名的文件的本地绝对路径(含扩展名)

def get_filen(path,extension_name):
    a=[]
    for filepath,dirnames,filenames in os.walk(path):
        for filename in filenames:
            stri=filename
            if extension_name in stri:
                stri=stri.replace(str(extension_name), "");
                a.append(stri)
                #print(string)
    return a
# 获取一个目录下所有指定扩展名的文件的名称(不含扩展名)


fpc=get_filep(r'C:\Users\ZHANYUAN\Desktop\学习\whk-my-obs',r'.md')
# 文件目录列表
#print(fpc)
fnc=get_filen(r'C:\Users\ZHANYUAN\Desktop\学习\whk-my-obs',r'.md')
# 文件名称(不含扩展名)列表
#print(fnc)
file_linked_num=[]
# 文件被链接的次数

echarts_nodes=""
# echarts graph nodes/data 的数据 节点-存在的.md笔记
echarts_links=""
# echarts graph links 的数据 wikilink造成的链接,有向边
site_link=input("将要发布到的站点(根目录)链接：")
# 站点根目录,用于关系图链接

echarts_node_template_wcs='''
{
    "value": %d,
    "name": "%s",
    "symbolSize": %d,
    "url": "%s"
},
'''
# echarts 节点模板(带逗号)
echarts_node_template='''
{
    "value": %d,
    "name": "%s",
    "symbolSize": %d,
    "url": "%s"
}
'''
# echarts 节点模板(不带逗号)

# echarts_nodes=""
# for tmp in fnc:
#     file_names_linked.append("[["+tmp+"]]")
# wikilink格式的链接，用于在文件中查找,可替换为RR的(())链接

file_names_linked=[]
for tmp in fnc:
    file_names_linked.append("[["+tmp+"]]")
# wikilink格式的链接，用于在文件中查找,可替换为RR的(())链接

file_names_links=[]
for tmp in fnc:
    file_names_links.append(site_link+tmp+"/")
# 站点中的链接，用于关系图

 
echarts_link_template_wcs='''
{
    source: "%s",
    target: "%s"
},
'''
# echarts 链接模板(带逗号)
echarts_link_template='''
{
    source: "%s",
    target: "%s"
}
'''
# echarts 链接模板(不带逗号)

for filepath in fpc:
    file_object = open(filepath,'r')
    try: 
        for line in file_object:
             for linkn in fpnc:
                 if linkn in str(line):
                     echarts_links += echarts_link_template % (fnc[fpc.index(filepath)],linkn)
                     echarts_links += "\n"
                     file_linked_num[fpnc.index(linkn)]+=1
    finally:
         file_object.close()

print(echarts_links)
