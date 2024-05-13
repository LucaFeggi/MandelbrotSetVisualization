#include "view_window.c"
#include "view_messagebox.c"
#include "view_renderer.c"

int main(int argc, char *argv[]) {
        createWindow();
        showHelloWorld();

        const char *message ="Bye World";
        showMessage(message);

        createLine();
        getchar();
}
