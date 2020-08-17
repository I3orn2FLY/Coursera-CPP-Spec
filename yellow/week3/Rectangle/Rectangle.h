//
// Created by kenny on 14/08/2020.
//

#ifndef RECTANGLE_RECTANGLE_H
#define RECTANGLE_RECTANGLE_H


class Rectangle {
public:
    Rectangle(int width, int height);

    int GetArea() const;

    int GetPerimeter() const;

    int GetWidth() const;

    int GetHeight() const;

private:
    int width_, height_;
};


#endif //RECTANGLE_RECTANGLE_H
