
#pragma once
#include "library/sp.h"

#include "control.h"
#include "forms_enums.h"
#include "framework/font.h"

namespace OpenApoc
{

class Label : public Control
{

  private:
	UString text;
	sp<BitmapFont> font;

  protected:
	virtual void OnRender() override;

  public:
	HorizontalAlignment TextHAlign;
	VerticalAlignment TextVAlign;
	bool WordWrap;

	Label(const UString &Text = "", sp<BitmapFont> font = nullptr);
	virtual ~Label();

	virtual void EventOccured(Event *e) override;
	virtual void Update() override;
	virtual void UnloadResources() override;

	UString GetText() const;
	void SetText(const UString &Text);

	sp<BitmapFont> GetFont() const;
	void SetFont(sp<BitmapFont> NewFont);

	virtual sp<Control> CopyTo(sp<Control> CopyParent) override;
	virtual void ConfigureFromXML(tinyxml2::XMLElement *Element) override;
};

}; // namespace OpenApoc
