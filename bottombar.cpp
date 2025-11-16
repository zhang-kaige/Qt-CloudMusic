#include "bottombar.h"
#include "ui_bottombar.h"

BottomBar::BottomBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BottomBar)
{
    ui->setupUi(this);
    auto pb = ui->pauseBtn;
    ui->nextBtn->setIcon(QIcon(":/images/traynext.png"));
    ui->lastBtn->setIcon(QIcon(":/images/traylast.png"));
    ui->loveBtn->setIcon(QIcon(":/images/爱心.svg"));
    ui->styleBtn->setIcon(QIcon(":/images/刷新.svg"));
    // 1) 基本属性
    pb->setObjectName("pb");                         // 若用 #pb 选择器必须有
    pb->setToolButtonStyle(Qt::ToolButtonIconOnly);
    pb->setAutoRaise(true);
    pb->setFocusPolicy(Qt::NoFocus);
    pb->setCursor(Qt::PointingHandCursor);
    pb->setCheckable(true);                          // 需要 :checked 才生效

    // 2) 图标与尺寸
    pb->setIcon(QIcon(":/images/播放.svg"));    // PNG 就用白色素材，或改用 SVG+currentColor
    pb->setIconSize(QSize(22,22));                   // 按需

    // 3) 样式表
    pb->setStyleSheet(
        "#pb{"
        "  background:#ff3b5c;"
        "  color:white;"                /* 若是SVG+currentColor可生效 */
        "  border:none;"
        "  border-radius:24px;"         /* 半径=尺寸一半 → 圆 */
        "  min-width:48px; min-height:48px;"
        "  max-width:48px; max-height:48px;"
        "  padding:0;"
        "}"
        "#pb:hover{ background:#ff2f52; }"
        "#pb:pressed{ background:#e52845; }"
        "#pb:disabled{ background:#e0e0e0; color:#bdbdbd; }"
        "#pb:checked{ background:#ff3b5c; }"
    );
}

BottomBar::~BottomBar()
{
    delete ui;
}
