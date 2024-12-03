#include <iostream>

class Window
{
    int x = 0, y = 0, weight = 1, height = 1;

    public:

    void setCoors(){
        while(true)
        {
            int tempX, tempY;
            std::cout << "Enter coordinates wiht a space ([x] [y]). The coordinates must be positive numbers" << std::endl;
            std::cin >> tempX >> tempY;
            if(tempX < 0 || tempY < 0) 
                std::cout << "The coordinates must be positive numbers. Try again" << std::endl;
            else if(tempX > 80 || tempY > 50) 
                std::cout << "X coordinate must be less than 81, Y coordinate must be less than 51. Try again" << std::endl;
            else if(tempX + weight > 80 || tempY + height > 50)
            {
                std::cout << "With the entered coordinates, the current window does not fit into the screen"  << std::endl;
                std::cout << "Current window size:" << std::endl;
                std::cout << weight << " " << height << std::endl;
            }
            else 
            {
                x = tempX;
                y = tempY;
                std::cout << "New coordinates have been set!" << std::endl;
                break;
            }
        }
    }

    void setSize()
    {
        int tempWeight, tempHeight;
        while(true)
        {
            int tempWeight, tempHeight;
            std::cout << "Enter sizes wiht a space ([weight] [height]). The coordinates must be positive numbers" << std::endl;
            std::cin >> tempWeight >> tempHeight;
            if(tempWeight < 0 || tempHeight < 0) 
                std::cout << "The sizes must be positive numbers. Try again" << std::endl;
            else if(tempWeight > 80 || tempHeight > 50) 
                std::cout << "Weight must be less than 81, height coordinate must be less than 51. Try again" << std::endl;
            else if(x + tempWeight > 80 || y + tempHeight > 50)
            {
                std::cout << "With the entered sizes, the current window does not fit into the screen"  << std::endl;
                std::cout << "Current window coordinates:" << std::endl;
                std::cout << x << " " << y << std::endl;
            }
            else 
            {
                weight = tempWeight;
                height = tempHeight;
                std::cout << "New sizes have been set!" << std::endl;
                break;
            }
        }
    }

    friend class Monitor;

};

class Monitor
{
    bool arr[50][80]{}; 

    public:
    void clear()
    {
        for (int i = 0; i < 80; i++) {
            for (int j = 0; j < 50; j++) {
                arr[j][i] = false;
            }
        }
    }

    void setWindow(const Window& window)
    {
        for (int i = window.x; i < window.x + window.weight; i++) {
            for (int j = window.y; j < window.y + window.height; j++) {
                arr[j][i] = true;
            }
        }
    }

    void display(){
        //int n =0;

        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 80; j++) {
                arr[i][j] ? std::cout << "1" : std::cout << "0";
            }
                //n++;
                //std::cout << n;
                std::cout << std::endl;
        }
    }

    friend Window;
};

int main() {
    
Monitor* monitor = new Monitor;
Window* window = new Window;

std::string inputCommand;
while(true){
    std::cout << "Enter the command(move, resize, display, close):" << std::endl;
    std::cin >> inputCommand;
    if (inputCommand == "move") window->setCoors();
    else if (inputCommand == "resize") window->setSize();
    else if (inputCommand == "display") 
    {
        monitor->clear();
        monitor->setWindow(*window);
        monitor->display();
    }
    else if (inputCommand == "close") break;
}

monitor->display();
delete monitor;
delete window;

    return 0;
}