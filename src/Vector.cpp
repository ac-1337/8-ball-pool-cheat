#include "Vector.h"
#include "Ball.h"
#include "Utils.h"
#include "TableInfo.h"

#include <algorithm>
#include "GlobalVars.h"

vec_t Vector2D::length() const
{
    return sqrt(this->x * this->x + this->y * this->y);
}

void Vector2D::print(const char* prefix, const char* suffix) const
{
    printf("%s%.15f, %.15f%s", prefix, this->x, this->y, suffix);
}

bool Vector2D::isNull() const
{ 
    return ((this->x == vecZero) && (this->y == vecZero));
}

vec_t Vector2D::getDistanceTo(const Vector2D& destination) const
{
    Vector2D buffer;
    buffer.x = (this->x - destination.x);
    buffer.y = (this->y - destination.y);
    return buffer.length();
}

void worldAxisesToScreenAxises(const Vector2D& pos, Vector2D* out)
{
    out->x = pos.x + TableInfo::getTableBoundX();
    out->y = pos.y + TableInfo::getTableBoundY();
    out->y = -out->y;
}

Vector2D Vector2D::toScreen() const
{
    Vector2D position, positinScale, screenPosition;

    position.x = this->x;
    position.y = this->y;

    worldAxisesToScreenAxises(position, &position);

    positinScale.x = TableInfo::getWidth()  / (TableInfo::getTableBoundX() * 2.0);
    positinScale.y = TableInfo::getHeight() / (TableInfo::getTableBoundY() * 2.0);

    screenPosition.x  = TableInfo::Position::left();
    screenPosition.x += position.x * positinScale.x;

    screenPosition.y  = TableInfo::Position::bottom();
    screenPosition.y += position.y * positinScale.y;

    return screenPosition;
}

void Vector3D::print(const char* prefix, const char* suffix) const
{
    printf("%s%.15f, %.15f, %.15f%s", prefix, this->x, this->y, this->z, suffix);
}

vec_t Vector3D::length() const
{
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

bool Vector3D::isNull() const
{
    return ((this->x == vecZero) && (this->y == vecZero) && (this->z == vecZero));
}
