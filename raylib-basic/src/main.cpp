#include "raylib.h"
#include "rlImGui.h"
#include "imgui.h"

int main(void) {
    const int screenWidth = 1000;
    const int screenHeight = 650;

    InitWindow(screenWidth, screenHeight, "raylib + rlImGui docking example");
    SetTargetFPS(60);

    rlImGuiSetup(true);

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    float circleX = screenWidth * 0.5f;
    float circleY = screenHeight * 0.5f;
    float radius = 30.0f;
    Color circleColor = MAROON;
    bool showDemoWindow = true;

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_RIGHT)) circleX += 3.0f;
        if (IsKeyDown(KEY_LEFT)) circleX -= 3.0f;
        if (IsKeyDown(KEY_UP)) circleY -= 3.0f;
        if (IsKeyDown(KEY_DOWN)) circleY += 3.0f;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Hello from raylib", 20, 20, 40, DARKBLUE);
        DrawText("Arrow keys move the circle", 20, 70, 20, GRAY);
        DrawCircle((int)circleX, (int)circleY, radius, circleColor);

        rlImGuiBegin();

        ImGuiWindowFlags dockspaceFlags = ImGuiWindowFlags_MenuBar |
            ImGuiWindowFlags_NoDocking |
            ImGuiWindowFlags_NoTitleBar |
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoBringToFrontOnFocus |
            ImGuiWindowFlags_NoNavFocus |
            ImGuiWindowFlags_NoBackground;

        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->Pos);
        ImGui::SetNextWindowSize(viewport->Size);
        ImGui::SetNextWindowViewport(viewport->ID);

        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        ImGui::Begin("DockSpaceRoot", nullptr, dockspaceFlags);
        ImGui::PopStyleVar(2);

        ImGuiID dockspaceId = ImGui::GetID("MainDockSpace");
        ImGui::DockSpace(dockspaceId, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_PassthruCentralNode);

        ImGui::End();

        ImGui::Begin("Controls");
        ImGui::Text("Dear ImGui docking is enabled");
        ImGui::Checkbox("Show ImGui Demo", &showDemoWindow);
        ImGui::SliderFloat("Radius", &radius, 5.0f, 120.0f);
        ImGui::SliderFloat("X", &circleX, 0.0f, (float)screenWidth);
        ImGui::SliderFloat("Y", &circleY, 0.0f, (float)screenHeight);

        float color[4] = {
            circleColor.r / 255.0f,
            circleColor.g / 255.0f,
            circleColor.b / 255.0f,
            circleColor.a / 255.0f
        };

        if (ImGui::ColorEdit4("Circle color", color)) {
            circleColor.r = (unsigned char)(color[0] * 255.0f);
            circleColor.g = (unsigned char)(color[1] * 255.0f);
            circleColor.b = (unsigned char)(color[2] * 255.0f);
            circleColor.a = (unsigned char)(color[3] * 255.0f);
        }
        ImGui::End();

        ImGui::Begin("Scene");
        ImGui::Text("Scene renders to raylib background.");
        ImGui::Text("Try dragging this tab and Controls tab around.");
        ImGui::End();

        if (showDemoWindow) {
            ImGui::ShowDemoWindow(&showDemoWindow);
        }

        rlImGuiEnd();
        EndDrawing();
    }

    rlImGuiShutdown();
    CloseWindow();
    return 0;
}
