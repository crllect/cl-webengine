#include "interface.h"

SharedLibrary::SharedLibrary() {
    int argc = 1;
    char* argv[] = { (char*)"sharedlibrary.lib", NULL };
    app = new QApplication(argc, argv);
}

int SharedLibrary::exec() {
    return app->exec();
}

void* initialize() {
    return new SharedLibrary();
}

void* newQWidget() {
    QWidget *widget = new QWidget;
    return widget;
}

void* newQVBoxLayout() {
    QVBoxLayout *layout = new QVBoxLayout;
    return layout;
}

void* newQWebEngineView() {
    QWebEngineView *webEngineView = new QWebEngineView();
    return webEngineView;
}

void webEngineViewLoad(void* webEngineView, char* url) {
    QWebEngineView *_webEngineView = reinterpret_cast<QWebEngineView*>(webEngineView);
    _webEngineView->setUrl(QUrl(url));
}

void layoutAddWidget(void* layout, void* widget) {
    QLayout *_layout = reinterpret_cast<QLayout*>(layout);
    QWidget *_widget = reinterpret_cast<QWidget*>(widget);
    _layout->addWidget(_widget);
}

void widgetSetLayout(void* widget, void* layout) {
    QWidget *_widget = reinterpret_cast<QWidget*>(widget);
    QLayout *_layout = reinterpret_cast<QLayout*>(layout);
    _widget->setLayout(_layout);
}

void widgetShow(void* widget) {
    QWidget *_widget = reinterpret_cast<QWidget*>(widget);
    _widget->show();
}

void widgetResize(void* widget, int width, int height) {
    QWidget *_widget = reinterpret_cast<QWidget*>(widget);
    _widget->resize(width, height);
}

void widgetSetFixedHeight(void* widget, int height) {
    QWidget *_widget = reinterpret_cast<QWidget*>(widget);
    _widget->setFixedHeight(height);
}

void windowSetWindowTitle(void* window, char* title) {
    QWidget *_window = reinterpret_cast<QWidget*>(window);
    _window->setWindowTitle(title);
}

void layoutSetContentsMargins(void* layout, int left, int top, int right, int bottom) {
    QLayout *_layout = reinterpret_cast<QLayout*>(layout);
    _layout->setContentsMargins(left, top, right, bottom);
}

void layoutSetSpacing(void* layout, int spacing) {
    QLayout *_layout = reinterpret_cast<QLayout*>(layout);
    _layout->setSpacing(spacing);
}

void layoutInsertWidget(void* layout, int index, void* widget) {
    QBoxLayout *_layout = reinterpret_cast<QBoxLayout*>(layout);
    QWidget *_widget = reinterpret_cast<QWidget*>(widget);
    _layout->insertWidget(index, _widget);
}

int main (int argc, char** argv) {
    QApplication* app = new QApplication(argc, argv);

    QWidget *window = reinterpret_cast<QWidget*>(newQWidget());
    QWebEngineView *webview = reinterpret_cast<QWebEngineView*>(newQWebEngineView());
    QVBoxLayout *layout = reinterpret_cast<QVBoxLayout*>(newQVBoxLayout());
    widgetShow(webview);
    webEngineViewLoad(webview, (char*)"https://www.duckduckgo.com");
    layoutAddWidget(layout, webview);
    widgetSetLayout(window, layout);
    widgetShow(window);
    windowSetWindowTitle(window, (char*)"Title");
    widgetResize(window, 1024, 768);

    return app->exec();
}