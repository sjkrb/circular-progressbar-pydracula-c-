#include "circularprogressbar.h"
#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QTextDocument>
#include <QDebug>
CircularProgressBar::CircularProgressBar(QWidget *parent) : QWidget(parent)
{
    m_value = 0.0f;
    m_width = 200;
    m_height = 200;
    m_progress_width = 10;
    m_margin = 0;
    m_max_value = 100;
    m_progress_rounded_cap = true;
    m_enable_shadow = true;
    m_progress_color = QColor(Qt::white);
    m_text_color = QColor(Qt::black);
    m_bg_progress_color = QColor("#393c67aa");

    resize(m_width,m_height);
}

void CircularProgressBar::setValue(float value)
{
    m_value = value;
}

void CircularProgressBar::setText_color(const QColor &text_color)
{
    m_text_color = text_color;
}

void CircularProgressBar::setProgress_color(const QColor &progress_color)
{
    m_progress_color = progress_color;
}

void CircularProgressBar::setEnable_shadow(bool enable_shadow)
{
    m_enable_shadow = enable_shadow;
}

void CircularProgressBar::setProgress_rounded_cap(bool progress_rounded_cap)
{
    m_progress_rounded_cap = progress_rounded_cap;
}

void CircularProgressBar::setMax_value(int max_value)
{
    m_max_value = max_value;
}

void CircularProgressBar::setProgress_width(int progress_width)
{
    m_progress_width = progress_width;
}

void CircularProgressBar::setHeight(int height)
{
    m_height = height;
}

void CircularProgressBar::setWidth(int width)
{
    m_width = width;
}

int CircularProgressBar::width() const
{
    return m_width;
}

void CircularProgressBar::add_shadow(bool enable)
{
    if(enable)
    {
        QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect;
        shadow->setBlurRadius(10);
        shadow->setXOffset(0);
        shadow->setYOffset(0);
        shadow->setColor(QColor(0,0,0,250));
        setGraphicsEffect(shadow);
    }
}

void CircularProgressBar::_onValueChange(float value)
{
    m_value = value;
    repaint();
}

void CircularProgressBar::_onTextChange(QString str)
{
    m_text = str;
    repaint();
}

float CircularProgressBar::value() const
{
    return m_value;
}

void CircularProgressBar::setMargin(int margin)
{
    m_margin = margin;
}

void CircularProgressBar::setBg_progress_color(const QColor &bg_progress_color)
{
    m_bg_progress_color = bg_progress_color;
}

void CircularProgressBar::setText(const QString &text)
{
    m_text = text;
}

void CircularProgressBar::setCircle_color(const QColor &circle_color)
{
    m_circle_color = circle_color;
}

int CircularProgressBar::height() const
{
    return m_height;
}

void CircularProgressBar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    int   width     = m_width - m_progress_width;
    int   height    = m_height - m_progress_width;
    float value     = m_value * 360 / m_max_value;

    QPainter *painter = new QPainter;
    painter->begin(this);
    painter->setPen(Qt::NoPen);
    painter->setRenderHint(QPainter::Antialiasing );
    painter->setRenderHint(QPainter::LosslessImageRendering);
    QRectF rectf = QRectF(0,0,m_width,m_height);

    QPen pen;
    painter->setPen(pen);

    pen.setWidth(m_progress_width);
    painter->setPen(pen);

    if(m_progress_rounded_cap)
        pen.setCapStyle(Qt::RoundCap);

    // default arc
    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(m_circle_color.name() + "aa"));
    painter->drawEllipse(rectf);

    // main arc
    pen.setColor(m_progress_color);
    pen.setWidth(m_progress_width);
    painter->setBrush(Qt::NoBrush);
    painter->setPen(pen);
    painter->drawArc(m_progress_width/2.0,m_progress_width/2.0,width,height,-90*16,-value*16);

    // circle
    painter->setBrush(m_circle_color);
    painter->setPen(Qt::NoPen);
    painter->drawEllipse(rectf.center(), (width-m_progress_width)/2.0, (height-m_progress_width)/2.0);

    // doc
    pen.setColor(m_text_color);
    painter->setPen(pen);

    QTextDocument doc;
    doc.setHtml(m_text);
    doc.setDocumentMargin(m_margin);
    doc.setTextWidth(width * 1.4/2.0 );
    QRectF textRect = QRectF(0,0,width * 1.4/2.0, width * 1.4/2.0);
    doc.setPageSize(textRect.size());
    textRect.moveCenter(rectf.center());
    painter->translate(textRect.topLeft());
    doc.drawContents(painter);

    painter->end();

}
