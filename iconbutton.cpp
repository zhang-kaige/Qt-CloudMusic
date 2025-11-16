#include "iconbutton.h"

IconButton::IconButton(QWidget *parent)
    :QToolButton(parent)
{
    setToolButtonStyle(Qt::ToolButtonIconOnly);   // 只显示图标
    setAutoRaise(true);                            // 扁平
    setFocusPolicy(Qt::NoFocus);                   // 不要焦点虚线
    setCursor(Qt::PointingHandCursor);
    setIconSize({20,20});
    setMinimumSize(28,28);                         // 提升可点击区域

    // 通用样式：无边框、hover/pressed 有轻底色
    setStyleSheet(
        "QToolButton{border:none;background:transparent;padding:0;}"
//        "QToolButton:hover{background:rgba(0,0,0,0.06);border-radius:6px;}"
        "QToolButton:pressed{background:rgba(0,0,0,0.12);}"
    );
}
