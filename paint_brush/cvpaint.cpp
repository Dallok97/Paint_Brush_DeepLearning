#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

vector<Rect> icons;
Mat	 image, canvas;;
int  mouse_mode = 0, draw_mode = 0;
Point	pt1, pt2;
Scalar  Color(0, 0, 0);
int		thickness = 2;

#include "menu.hpp"
#include "icon_flag.hpp"
#include "draw.hpp"
#include "event.hpp"

void  onTrackbar(int value, void*) {
    mouse_mode = 0;
}

int main()
{
    image = Mat(500, 800, CV_8UC3, Scalar(255, 255, 255));	
    place_icons(Size(60, 60));						         

    Rect last_icon = *(icons.end() - 1);				                           
    Point start_pale = Point(0, last_icon.br().y + 5);		                         

    icons.push_back(Rect(start_pale, Size(100, 100)));	                   		 
    icons.push_back(Rect(start_pale + Point(105, 0), Size(15, 100))); 			

    create_hueIndex(icons[HUE_IDX]);					                                    
    create_palette(start_pale.y, icons[PALETTE]);		               

    imshow("그림판", image);
    setMouseCallback("그림판", onMouse);

    createTrackbar("선굵기 ", "그림판", &thickness, 20, onTrackbar);
    int  x = icons[1].br().x;									                       
    Rect canvas_rect(x, 0, image.cols - x, image.rows);			          
    canvas = image(canvas_rect);									                       

    while (1)
    {
        if (mouse_mode == 1) 			                                                
            draw(image, Color);
        else if (mouse_mode == 3)			                                           
        {
            if (draw_mode == DRAW_BRUSH || draw_mode == ERASE) {
                draw(image, Color);
            }
            else {
                draw(image.clone());
            }
        }
        if (waitKey(30) == 27)  break;
    }

    waitKey();
    return 0;
}