
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double W, H;
    if (!(std::cin >> W >> H)) 
    {
        return 0;
    }

    double cx = 0.0;
    double cy = 0.0;
    double zoom = 1.0;

    std::string cmd;
    while (std::cin >> cmd) 
    {
        if (cmd == "VERS_MONDE") 
        {
            double px, py;
            std::cin >> px >> py;
            double mx = cx + (px - W / 2.0) / zoom;
            double my = cy + (py - H / 2.0) / zoom;
            if (std::abs(mx) < 0.005) { mx = 0.0; }
            if (std::abs(my) < 0.005) { my = 0.0; }
            std::cout << std::fixed << std::setprecision(2)
                      << "MONDE " << mx << " " << my << "\n";
        } 
        else if (cmd == "VERS_PIXEL") 
        {
            double mx, my;
            std::cin >> mx >> my;
            double px = (mx - cx) * zoom + W / 2.0;
            double py = (my - cy) * zoom + H / 2.0;
            if (std::abs(px) < 0.005) { px = 0.0; }
            if (std::abs(py) < 0.005) { py = 0.0; }
            std::cout << std::fixed << std::setprecision(2)
                      << "PIXEL " << px << " " << py << "\n";
        } 
        else if (cmd == "DEPLACE") 
        {
            double dx, dy;
            std::cin >> dx >> dy;
            cx = cx - dx / zoom;
            cy = cy - dy / zoom;
        } 
        else if (cmd == "ZOOM") 
        {
            double f, px, py;
            std::cin >> f >> px >> py;
            // Point du monde sous le curseur AVANT de changer le zoom
            double ax = cx + (px - W / 2.0) / zoom;
            double ay = cy + (py - H / 2.0) / zoom;

            zoom = zoom * f;
            if (zoom < 0.02) 
            {
                zoom = 0.02;
            }
            if (zoom > 64.0) 
            {
                zoom = 64.0;
            }

            cx = ax - (px - W / 2.0) / zoom;
            cy = ay - (py - H / 2.0) / zoom;
        } 
        else if (cmd == "GRILLE") 
        {
            double m;
            std::cin >> m;
            double s = 1.0;
            while (s * zoom < m) 
            {
                s *= 2.0;
            }
            while (s * 0.5 * zoom >= m) 
            {
                s *= 0.5;
            }
            std::cout << std::fixed << std::setprecision(6)
                      << "GRILLE " << s << "\n";
        } 
        else if (cmd == "ORIGINE") 
        {
            cx = 0.0;
            cy = 0.0;
            zoom = 1.0;
        }
    }

    if (std::abs(cx) < 0.005) { cx = 0.0; }
    if (std::abs(cy) < 0.005) { cy = 0.0; }

    std::cout << std::fixed << std::setprecision(2)
              << "CENTRE " << cx << " " << cy << "\n"
              << "ZOOM " << zoom << "\n";

    return 0;
}
