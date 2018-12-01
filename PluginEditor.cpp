/*
  ==============================================================================

	This file was auto-generated!

	It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
CompressorAudioProcessorEditor::CompressorAudioProcessorEditor(CompressorAudioProcessor& p)
	: AudioProcessorEditor(&p), processor(p),
	//thresholdSliderAttachment(processor.getParametersVTS(), "threshold", thresholdSlider),
	//ratioSliderAttachment(processor.getParametersVTS(), "ratio", ratioSlider),
	attackSliderAttachment(processor.getParametersVTS(), "attack", attackSlider),
	releaseSliderAttachment(processor.getParametersVTS(), "release", releaseSlider),
	makeUpGainSliderAttachment(processor.getParametersVTS(), "mug", makeUpGainSlider),
	compressionSliderAttachment(processor.getParametersVTS(), "compression", compressionSlider),
	makeUpGainSelectorButtonAttachment(processor.getParametersVTS(), "mugselector", makeUpGainSelectorButton),
	compressionTypeSelectorBoxAttachment(processor.getParametersVTS(), "comptype", compressionTypeSelectorBox)
{
	// Make sure that before the constructor has finished, you've set the
	// editor's size to whatever you need it to be.
	setSize(500, 500);

	makeUpGainSelectorButton.setButtonText("AUTO");
	makeUpGainSelectorButton.setClickingTogglesState(true);
	makeUpGainSelectorButton.setColour(TextButton::buttonOnColourId, compressionSlider.findColour(Slider::thumbColourId));

	compressionTypeSelectorBox.addItem("Speech", 0);
	compressionTypeSelectorBox.addItem("Guitar", 1);
	compressionTypeSelectorBox.addItem("Snare", 2);




	/*thresholdSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	thresholdSlider.setTextBoxStyle(Slider::TextBoxAbove, false, 65, 20);
	thresholdSlider.setTextValueSuffix(" dB");
	thresholdSlider.getLookAndFeel().setColour(Slider::textBoxOutlineColourId,
		getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
	

	thresholdSliderLabel.setText("THRESHOLD", dontSendNotification);
	thresholdSliderLabel.attachToComponent(&thresholdSlider, false);
	thresholdSliderLabel.setJustificationType(Justification::centredTop);
	thresholdSliderLabel.setFont(Font("Bahnschrift", "Light", 16));



	ratioSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	ratioSlider.setTextBoxStyle(Slider::TextBoxAbove, false, 65, 20);
	ratioSlider.setTextValueSuffix(":1");
	ratioSlider.getLookAndFeel().setColour(Slider::textBoxOutlineColourId,
		getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

	ratioSliderLabel.setText("RATIO", dontSendNotification);
	ratioSliderLabel.attachToComponent(&ratioSlider, false);
	ratioSliderLabel.setJustificationType(Justification::centredTop);
	ratioSliderLabel.setFont(Font("Bahnschrift", "Light", 16));*/



	attackSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	attackSlider.setTextBoxStyle(Slider::TextBoxAbove, false, 65, 20);
	attackSlider.setTextValueSuffix(" ms");
	attackSlider.getLookAndFeel().setColour(Slider::textBoxOutlineColourId,
		getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

	attackSliderLabel.setText("ATTACK", dontSendNotification);
	attackSliderLabel.attachToComponent(&attackSlider, false);
	attackSliderLabel.setJustificationType(Justification::centredTop);
	attackSliderLabel.setFont(Font("Bahnschrift", "Light", 16));



	releaseSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	releaseSlider.setTextBoxStyle(Slider::TextBoxAbove, false, 65, 20);
	releaseSlider.setTextValueSuffix(" ms");
	releaseSlider.getLookAndFeel().setColour(Slider::textBoxOutlineColourId,
		getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

	releaseSliderLabel.setText("RELEASE", dontSendNotification);
	releaseSliderLabel.attachToComponent(&releaseSlider, false);
	releaseSliderLabel.setJustificationType(Justification::centredTop);
	releaseSliderLabel.setFont(Font("Bahnschrift", "Light", 16));



	makeUpGainSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	makeUpGainSlider.setTextBoxStyle(Slider::TextBoxAbove, false, 40, 10);
	makeUpGainSlider.setTextValueSuffix(" dB");
	makeUpGainSlider.getLookAndFeel().setColour(Slider::textBoxOutlineColourId,
		getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

	makeUpGainSliderLabel.setText("MAKE UP GAIN", dontSendNotification);
	makeUpGainSliderLabel.attachToComponent(&makeUpGainSlider, false);
	makeUpGainSliderLabel.setJustificationType(Justification::centredTop);
	makeUpGainSliderLabel.setFont(Font("Bahnschrift", "Light", 10));



	compressionSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	compressionSlider.setTextBoxStyle(Slider::TextBoxAbove, false, 65, 20);
	compressionSlider.setTextValueSuffix("");
	compressionSlider.getLookAndFeel().setColour(Slider::textBoxOutlineColourId,
		getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
	

	compressionSliderLabel.setText("COMPRESSION", dontSendNotification);
	compressionSliderLabel.attachToComponent(&compressionSlider, false);
	compressionSliderLabel.setJustificationType(Justification::centredTop);
	compressionSliderLabel.setFont(Font("Bahnschrift", "Light", 16));



	//addAndMakeVisible(thresholdSlider);
	//addAndMakeVisible(ratioSlider);
	addAndMakeVisible(attackSlider);
	addAndMakeVisible(releaseSlider);
	addAndMakeVisible(makeUpGainSlider);
	addAndMakeVisible(compressionSlider);
	addAndMakeVisible(makeUpGainSelectorButton);
	addAndMakeVisible(compressionTypeSelectorBox);

	//addAndMakeVisible(thresholdSliderLabel);
	//addAndMakeVisible(ratioSliderLabel);
	addAndMakeVisible(attackSliderLabel);
	addAndMakeVisible(releaseSliderLabel);
	addAndMakeVisible(makeUpGainSliderLabel);
	addAndMakeVisible(compressionSliderLabel);


}

CompressorAudioProcessorEditor::~CompressorAudioProcessorEditor()
{
}

//==============================================================================
void CompressorAudioProcessorEditor::paint(Graphics& g)
{
	// (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
}

void CompressorAudioProcessorEditor::resized()
{
	// This is generally where you'll want to lay out the positions of any
	// subcomponents in your editor..
	attackSlider.setBounds(0, 30, 200, 120);
	releaseSlider.setBounds(200, 30, 200, 120);
	//attackSlider.setBounds(0, 180, 200, 120);
	//releaseSlider.setBounds(200, 180, 200, 120);
	makeUpGainSlider.setBounds(400, 100, 70, 70);
	compressionSlider.setBounds(0, 180, 400, 300);
	makeUpGainSelectorButton.setBounds(420, 400, 50, 30);
	compressionTypeSelectorBox.setBounds(420, 300, 50, 30);

	/*if (*processor.getParametersVTS().getRawParameterValue("mugselector") < 1) {
		makeUpGainSlider.setEnabled(false);
	}*/

	
}
