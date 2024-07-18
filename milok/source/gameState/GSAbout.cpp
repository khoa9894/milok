#include "GSAbout.h"
GSAbout::GSAbout() {

}
GSAbout::~GSAbout()
{
	//if (pi != nullptr) delete pi;
	if (butt != nullptr) delete butt;
	if (ex != nullptr) delete ex;
}
void GSAbout::openGitHubLink(const std::string& url) {
	sf::TcpSocket socket;
	sf::Socket::Status status = socket.connect(url, 80); // Connect directly using URL
	if (status == sf::Socket::Done) {
		socket.disconnect();
	}
	else {
		std::cerr << "Failed to connect to " << url << std::endl;
	}
}
void GSAbout::Exit()
{
}

void GSAbout::Resume()
{
}

void GSAbout::Pause()
{
}

void GSAbout::Init()
{
	pi.setTexture(*resourceManage::GetInstance()->gtTexture("background"));
	butt = new gameButton();
	butt->Init("github_PNG40");
	butt->setOrigin(butt->getSize() / 2.f);
	butt->setPosition(sf::Vector2f(971 / 2, 500 / 2 + 500 / 10 + 60 - 40));
	butt->setClick([this]() {this->openGitHubLink("https://github.com/khoa9894"); });
}

void GSAbout::Update(sf::Clock& cc)
{
}

void GSAbout::Render(sf::RenderWindow* window)
{
	window ->draw(pi);
	butt->Render(window); 

}
