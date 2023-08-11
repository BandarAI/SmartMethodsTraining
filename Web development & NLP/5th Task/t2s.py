import speech_recognition as sr
from gtts import gTTS

t2s = sr.Recognizer()

with sr.Microphone() as speaker:
    print("Speak....")
    audio = t2s.listen(speaker)

text = t2s.recognize_google(audio)
if text:
    print(text)
elif not audio:
    print("Cant detect audio")
else:
    print("No recognized speech")

speech = gTTS(text)

speech.save("output.mp3")

print("Audio file saved")
