package edu.bzu.llm;

import io.github.stefanbratanov.jvm.openai.*;

public class GeminiIntegration {

    private static final String API_KEY = "AIzaSyCm1O5TbmSnH-Z9xpInGIHcCgmhegHMdls";

    public static void main(String[] args) {
        // Define the prompt
        String prompt = "Explain the benefits of using Java for web development.";

        // Send the request and handle the response
        try {
            OpenAI openAI = OpenAI.newBuilder(API_KEY).build();

            ChatClient chatClient = openAI.chatClient();
            CreateChatCompletionRequest createChatCompletionRequest = CreateChatCompletionRequest.newBuilder()
                    .model(OpenAIModel.GPT_3_5_TURBO)
                    .message(ChatMessage.userMessage(prompt))
                    .build();
            ChatCompletion chatCompletion = chatClient.createChatCompletion(createChatCompletionRequest);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}