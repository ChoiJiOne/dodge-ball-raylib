#pragma once

#include "Manager/IManager.h"
#include "Render/IRenderableModel.h"

class RenderManager : public IManager<RenderManager>
{
public:
	DISALLOW_COPY_AND_ASSIGN(RenderManager);

	virtual Result<void> Startup() override;
	virtual Result<void> Shutdown() override;

	void BeginFrame(float r, float g, float b, float a);
	void EndFrame();

	void Render(const IRenderableModel* renderableModel);

private:
	friend class IManager<RenderManager>;

	RenderManager() = default;
	virtual ~RenderManager() = default;
};