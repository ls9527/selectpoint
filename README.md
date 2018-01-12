# selectpoint
12306 图片点击控件（基于MFC）
vs2012编译通过
vc110_xp 可用

项目演示：
![image](https://github.com/ls9527/selectpoint/blob/master/doc/show.gif)

MFC3100 是自定义控件，会有关联。不推荐使用


SelectPoint是自定义控件核心内容

MFCTest是调用SelectPoint 模块的一个演示

## 创建控件
RECT rect = {0,0,293,190};
sr.Create(NULL,WS_VISIBLE|WS_CHILD|SS_OWNERDRAW|SS_NOTIFY,rect,this);
这样就可以再当前窗口创建这个控件，并进行使用过了。

### 获取所有点列表
vector<LPSealRect> points;
sr.GetPoints(points);

