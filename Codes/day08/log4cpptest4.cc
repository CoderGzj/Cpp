#include <iostream>

#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>

using std::cout;
using std::endl;
using namespace log4cpp;

void test0() {
    // 0.创建PatternLayout 对象
    PatternLayout * ptnLayout1 = new PatternLayout();
    ptnLayout1->setConversionPattern("%d [%c] [%p] %m%n");

    PatternLayout * ptnLayout2 = new PatternLayout();
    ptnLayout2->setConversionPattern("%d [%c] [%p] %m%n");

    PatternLayout * ptnLayout3 = new PatternLayout();
    ptnLayout3->setConversionPattern("%d [%c] [%p] %m%n");

    // 1.创建目的地对象
    OstreamAppender * posAp = new OstreamAppender("console", &cout);
    FileAppender * fileAp = new FileAppender("fileApp", "wd.log");
    auto * rfApp = new RollingFileAppender("rollingFileApp", 
    "rollingwd.log", 5000, 9);

    // 2.设置目的地日志布局
    posAp->setLayout(ptnLayout1);
    fileAp->setLayout(ptnLayout2);
    rfApp->setLayout(ptnLayout3);

    // 3.创建 Category 对象
    Category & root = Category::getRoot();

    // 4.设置优先级
    root.setPriority(Priority::DEBUG);

    root.setAppender(posAp);
    root.setAppender(fileAp);
    root.setAppender(rfApp);
    Category & module1 = root.getInstance("register");

    // 5.进行日志记录
    module1.emerg("this is an emerge message");
    module1.alert("this is an alert message");
    module1.crit("this is an crit message");
    module1.debug("xxxx");

    // 6.释放申请资源，回收日志系统
    Category::shutdown();
}

int main() {
    test0();
}
