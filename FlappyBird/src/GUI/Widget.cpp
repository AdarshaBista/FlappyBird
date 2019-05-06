#include "Widget.h"


Widget::Widget()
{
}


// Animations
Widget::Animation::Animation()
{
	scaleFactor = { 1.0f, 1.0f };
	maxScale = 1.15f;
	speed = 0.05f;
	coverColor = sf::Color(50, 50, 50);
}

void Widget::Animation::enlarge(Widget* widget)
{
	scaleFactor += {speed, speed};

	if (scaleFactor.x > maxScale)
		scaleFactor = { maxScale, maxScale };

	widget->setScale(scaleFactor);
}

void Widget::Animation::cover(Widget* widget)
{
	widget->setColor(coverColor);
}

void Widget::Animation::resetEnlarge(Widget* widget)
{
	scaleFactor -= {speed, speed};

	if (scaleFactor.x < 1.0f)
		scaleFactor = { 1.0f, 1.0f };

	widget->setScale(scaleFactor);
}

void Widget::Animation::resetCover(Widget* widget)
{
	widget->setColor(sf::Color::White);
}
