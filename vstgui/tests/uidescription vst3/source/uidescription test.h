/*
 *  uidescription test.h
 *  uidescription test
 *
 *  Created by Arne Scheffler on 2/12/10.
 *  Copyright 2010 Arne Scheffler. All rights reserved.
 *
 */

#ifndef __uidescription_test__
#define __uidescription_test__

#include "public.sdk/source/vst/vstaudioeffect.h"
#include "vstgui/uidescription/vst3editor.h"
#include "pluginterfaces/base/ustring.h"

namespace VSTGUI {

//------------------------------------------------------------------------
class UIDescriptionBaseController : public Steinberg::Vst::EditController
{
public:
	Steinberg::tresult PLUGIN_API initialize (Steinberg::FUnknown* context);
	Steinberg::tresult beginEdit (Steinberg::Vst::ParamID tag);
	Steinberg::tresult performEdit (Steinberg::Vst::ParamID tag, Steinberg::Vst::ParamValue valueNormalized);
	Steinberg::tresult endEdit (Steinberg::Vst::ParamID tag);
	Steinberg::Vst::Parameter* getParameterObject (Steinberg::Vst::ParamID tag);
protected:
	Steinberg::Vst::ParameterContainer uiParameters;
};

//------------------------------------------------------------------------
class UIDescriptionTestProcessor : public Steinberg::Vst::AudioEffect
{
public:
	UIDescriptionTestProcessor ();
	
	Steinberg::tresult PLUGIN_API initialize (Steinberg::FUnknown* context);
	Steinberg::tresult PLUGIN_API setBusArrangements (Steinberg::Vst::SpeakerArrangement* inputs, Steinberg::int32 numIns, Steinberg::Vst::SpeakerArrangement* outputs, Steinberg::int32 numOuts);
	Steinberg::tresult PLUGIN_API process (Steinberg::Vst::ProcessData& data);

	static Steinberg::FUnknown* createInstance (void*) { return (Steinberg::Vst::IAudioProcessor*)new UIDescriptionTestProcessor; }
	static Steinberg::FUID cid;
};

//------------------------------------------------------------------------
class UIDescriptionTestController : public UIDescriptionBaseController
{
public:
	UIDescriptionTestController ();
	
	Steinberg::tresult PLUGIN_API initialize (Steinberg::FUnknown* context);
	Steinberg::IPlugView* PLUGIN_API createView (Steinberg::FIDString name);

	static Steinberg::FUnknown* createInstance (void*) { return (Steinberg::Vst::IEditController*)new UIDescriptionTestController; }
	static Steinberg::FUID cid;
};

} // namespace

#endif // __uidescription_test__