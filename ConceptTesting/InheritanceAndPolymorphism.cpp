#include <iostream>

class Vector2
{
public:
	float m_X, m_Y;
	Vector2(float x, float y)
		: m_X(x), m_Y(y) {}
	void Move(float dx, float dy)
	{
		m_X += dx;
		m_Y += dy;
	}
	virtual void PrintType()
	{
		std::cout << "Vector2\n";
	}
};

class Player : public Vector2
{
public:
	Player()
		: Vector2(0, 0) {}
	Player(float x, float y)
		: Vector2(x, y) {}
	void PrintName() const 
	{
		std::cout << m_X << ", " << m_Y << "\n";
	}
	void PrintType() override
	{
		std::cout << "Player\n";
	}
};

int main()
{
	Player player(5, 2);
	player.Move(0.2, 0.4);
	player.PrintName();
	player.PrintType();

	Vector2* p = new Player();
	p->PrintType();  // Prints Player if function marked as virtual, if not it prints Vector2
}
