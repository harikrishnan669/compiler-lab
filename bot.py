#!/usr/bin/env python3
import json
import urllib.request
import urllib.error
import sys

API_KEY = "AIzaSyAfqxELemA9q8GAg0beAxu0z4C0jWmi_zY"

MODEL_NAME = "gemini-2.5-flash"
API_URL = f"https://generativelanguage.googleapis.com/v1beta/models/{MODEL_NAME}:generateContent?key={API_KEY}"

SYSTEM_PROMPT = (
    "You are an expert assistant for a compiler design lab. "
    "Your answers must be straight, short, and technically valid. "
    "Focus on topics relevant to compiler construction like lexical analysis, "
    "parsing, symbol tables, code generation, and tools (lex, yacc, flex, bison)."
    "Avoid markdown and comments."
)

def call_gemini_api(user_query):
    payload = {
        "system_instruction": {"parts": [{"text": SYSTEM_PROMPT}]},
        "contents": [
            {"role": "user", "parts": [{"text": user_query}]}
        ]
    }

    data = json.dumps(payload).encode("utf-8")
    headers = {"Content-Type": "application/json"}

    req = urllib.request.Request(API_URL, data=data, headers=headers, method="POST")

    try:
        with urllib.request.urlopen(req) as response:
            result = json.loads(response.read().decode("utf-8"))
            return result["candidates"][0]["content"]["parts"][0]["text"]
    except Exception as e:
        return f"Error: {e}"

def main():
    print("--- Compiler Lab Chatbot ---")
    print(f"Using model: {MODEL_NAME}")
    print("Type 'exit' to stop.\n")

    while True:
        try:
            user_input = input("You: ").strip()
            if user_input.lower() in ["exit", "quit"]:
                print("Bot: Good luck with your exam!")
                break
            if not user_input:
                continue
            response = call_gemini_api(user_input)
            print("Bot:", response, "\n")
        except KeyboardInterrupt:
            print("\nBot: Good luck with your exam!")
            break

if __name__ == "__main__":
    main()