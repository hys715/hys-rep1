lst1 = [u'零', u'壹', u'贰', u'叁', u'肆', u'伍', u'陆', u'柒', u'捌', u'玖']
lst2 = [u'圆', u'拾', u'佰', u'仟', u'万', u'拾', u'佰', u'仟', u'亿']

a = int(input())
r = ''
if a < 0:
    r = u'负'
s = str(abs(a))[:: -1]
for i in range(len(s) - 1, -1, -1):
    if s[i] != '0' or i == 0 or i == 4 or i == 8:
        r = r + lst1[int(s[i])] + lst2[i]
        if i == 4 and s[i] == '0':
            r = r + u'零'
    else:
        r = r + u'零'
if a == 0:
    print(u'零圆')
else:
    print(r.replace(u'零零零', u'零').replace(u'零零', u'零').replace(u'零万', u'万').replace(u'零圆', u'圆'))
