#ifndef PAINT_BRUSH_V5_EVENT_HPP
#define PAINT_BRUSH_V5_EVENT_HPP

static void onMouse(int event, int x, int y, int, void*)
{
    Point pt(x, y);
    if (event == EVENT_LBUTTONUP) 				
    {
        for (int i = 0; i < (int)icons.size(); i++) 		
        {
            if (icons[i].contains(pt)) {					
                if (i < 6)  							
                {
                    mouse_mode = 0;					
                    draw_mode = i;					
                }
                else		command(i);					
                return;
            }
        }
        pt2 = pt;										
        mouse_mode = 1;								
    }
    else if (event == EVENT_LBUTTONDOWN) 	
    {
        pt1 = pt;										
        mouse_mode = 2;
    }

    if (mouse_mode >= 2) {							
        Rect rect(0, 0, 125, image.rows);
        mouse_mode = (rect.contains(pt)) ? 0 : 3;		
        pt2 = pt;
    }
}


#endif PAINT_BRUSH_V5_EVENT_HPP
