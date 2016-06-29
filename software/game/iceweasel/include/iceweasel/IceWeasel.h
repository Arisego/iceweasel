#pragma once

#include <Urho3D/Engine/Application.h>


namespace Urho3D {
    class Node;
    class Scene;
}


class IceWeasel : public Urho3D::Application
{
public:
    IceWeasel(Urho3D::Context* context);
    virtual void Setup() override;
    virtual void Start() override;
    virtual void Stop() override;

private:

    void CreateDebugHud();
    void CreateUI();
    void CreateScene();
    void CreateCamera();

    void SwitchCameraToFreeCam();
    void SwitchCameraToFPSCam();

    void HandleKeyDown(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData);
    void HandlePostRenderUpdate(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData);

    Urho3D::SharedPtr<Urho3D::Scene> scene_;
    Urho3D::SharedPtr<Urho3D::Node> cameraMoveNode_;
    Urho3D::SharedPtr<Urho3D::Node> cameraRotateNode_;
    Urho3D::SharedPtr<Urho3D::DebugHud> debugHud_;

    bool drawDebugGeometry_;
    bool cameraModeIsFreeCam_;
};
