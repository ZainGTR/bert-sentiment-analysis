# BERT Sentiment Analysis on Akash Network with Unreal engine plugin

This repository contains the necessary files to deploy a sentiment analysis model based on the BERT architecture on the Akash Network. The model is capable of classifying text into five sentiment categories: very negative, negative, neutral, positive, and very positive.

## Model

The model used is the `nlptown/bert-base-multilingual-uncased-sentiment` model from Hugging Face. This model is capable of understanding and generating text in multiple languages, making it versatile for various use cases.

## Files

- `app.py`: This is the main application file. It uses websocket server to get inputs from the unreal dedicated server.
- `Dockerfile`: This file contains the instructions to build the Docker image for the application.
- `requirements.txt`: This file lists the Python libraries required by the application.
- `deploy.yaml`: This is the SDL (Stack Definition Language) file used for deploying the application on the Akash Network.
- `index.html`: This file contains the HTML code for the application's user interface.

## Deployment on Akash Network

To deploy the application on the Akash Network, you need to have an Akash account with sufficient AKT balance. Follow the steps below:

1. Clone this repository.
2. Build the Docker image and push it to a Docker registry.
3. Update the `deploy.yaml` file with the correct Docker image path.
4. Use the Akash CLI or Akash Console to deploy the `deploy.yaml` file.

Please refer to the [Akash documentation](https://docs.akash.network/) for detailed instructions on deploying applications.

## Testing the Application

Once the application is deployed, you can test it by connecting via webSocket

# Sentiment Analysis Plugin for Unreal Engine

The Sentiment Analysis Plugin for Unreal Engine integrates WebSocket communication with a sentiment analysis service, allowing users to analyze and monitor sentiments of text messages within their Unreal Engine projects.

## Features

- Establish WebSocket connection to a sentiment analysis service.
- Send text messages for sentiment analysis.
- Receive sentiment analysis results in real-time.

## Installation

1. Clone or download this repository.
2. Copy the `SentimentAnalysisPlugin` folder into the `Plugins` directory of your Unreal Engine project.

## Usage

### Connecting to WebSocket

Usage
Create WebSocket
Use the CreateWebSocket or CreateWebSocketWithHeaders function to create a WebSocket connection.

Blueprint Node:

Create WebSocket
Create WebSocket With Headers
Send Message
Use the SendMessage function to send a message through the WebSocket.

*Blueprint Node*:

Send Message
Bind to Events
Bind to the following events to handle WebSocket events:

1. OnWebSocketConnected
2. OnWebSocketConnectionError
3. OnWebSocketClosed
4. OnWebSocketMessageReceived
5. OnWebSocketMessageSent

*Example*
Creating a WebSocket Connection:

```
UWebSocket* WebSocket = USentimentAnalysisBPLibrary::CreateWebSocket("ws://localhost:8765");
WebSocket->OnWebSocketConnected.AddDynamic(this, &YourClass::HandleWebSocketConnected);
WebSocket->OnWebSocketMessageReceived.AddDynamic(this, &YourClass::HandleWebSocketMessageReceived);
WebSocket->Connect();
```
Sending a Message:

```
if (WebSocket->IsConnected())
{
    WebSocket->SendMessage("Hello, WebSocket!");
}
```
Handling Events:

```
void YourClass::HandleWebSocketConnected()
{
    // Handle WebSocket connected event
}

void YourClass::HandleWebSocketMessageReceived(const FString& Message)
{
    // Handle WebSocket message received event
}
```


## Contributing

Contributions are welcome! If you encounter any issues or have suggestions for improvements, please [open an issue](https://github.com/bert-sentiment-analysis/issues).

## License

This plugin is licensed under the MIT License. See [LICENSE](LICENSE) for more information.
