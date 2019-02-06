#ifndef qt_renderer_h
#define qt_renderer_h

#include "../skeleton/service.h"
#include "rendering_controller_impl_base.h"

#include <QApplication>
#include <QWindow>
#include <QProgressBar>
#include <QSlider>
#include <QEventLoop>


class LeQtRenderer : public LeRenderingControllerImplBase , public LeService<LeQtRenderer>
{

    QWindow* window; 
    
    public:
        bool init() {
            int c=0;
            char* v[1];
            std::string qa("asd");
            v[1] = const_cast<char*>(qa.c_str());
            QApplication a(c,v);
            QWindow* window = new QWindow;
            
            //MyEventLoop l(qApp);
            //window->setFixedSize(200, 80);

            QProgressBar *progressBar = new QProgressBar();
            progressBar->setRange(0, 100);
            progressBar->setValue(0);
            progressBar->setGeometry(10, 10, 180, 30);

            QSlider *slider = new QSlider();
            slider->setOrientation(Qt::Horizontal);
            slider->setRange(0, 100);
            slider->setValue(0);
            slider->setGeometry(10, 40, 180, 30);

            QObject::connect(slider, SIGNAL (valueChanged(int)), progressBar, SLOT (setValue(int)));
            QObject::connect(slider, SIGNAL (valueChanged(int)), progressBar, SLOT (setValue(int)));
            window->show();
            a.exec();
        }
        
        LeQtRenderer() {
            init();
        }
    
    public:
		void set_drawing_color(int r, int g, int b) { }
		void set_background_image(const char* path) { }
        void draw_image(const char* ipath, unsigned int y, unsigned int x, unsigned int cropw, unsigned int croph) { }
		void draw_image(const char* ipath, unsigned int y, unsigned int x, unsigned int cropw, unsigned int croph, double angle, bool needflip, unsigned int flipdir) { }	
		bool draw_scroll_background(unsigned int delta) { }
        void draw_static_background() { }
        
        void zoomin(int factor) { }
        void zoomout(int factor) { }
        void fzoomin(int step) { }
        void fzoomout(int step) { }

        void pan_up(int step) { }
        void pan_down(int step) { }
        void pan_left(int step) { }
        void pan_right(int step) { }
        void pan_to_x_y(int x, int y) { }

    private:
        
    
};


#endif
