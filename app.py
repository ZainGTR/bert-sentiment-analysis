import asyncio
import websockets
import json
from scipy.special import softmax
from transformers import AutoTokenizer, AutoModelForSequenceClassification
import numpy as np

# Load the pre-trained model and tokenizer
MODEL_NAME = 'nlptown/bert-base-multilingual-uncased-sentiment'
tokenizer = AutoTokenizer.from_pretrained(MODEL_NAME)
model = AutoModelForSequenceClassification.from_pretrained(MODEL_NAME)

sentiment_labels = ['very negative', 'negative', 'neutral', 'positive', 'very positive']

async def analyze_sentiment(text):
    encoded_input = tokenizer(text, return_tensors='pt')
    output = model(**encoded_input)
    scores = output[0][0].detach().numpy()
    scores = softmax(scores)
    ranking = np.argmax(scores)
    sentiment = sentiment_labels[ranking]
    return sentiment

async def handler(websocket, path):
    async for message in websocket:
        print(f"Received message: {message}")
        
        # Perform sentiment analysis
        sentiment = await analyze_sentiment(message)
        
        # Send the result back to the client
        response = json.dumps({"text": message, "sentiment": sentiment})
        await websocket.send(response)

async def main():
    async with websockets.serve(handler, "localhost", 8765):
        print("WebSocket server is running on ws://localhost:8765")
        await asyncio.Future()  # Run forever

if __name__ == "__main__":
    asyncio.run(main())
