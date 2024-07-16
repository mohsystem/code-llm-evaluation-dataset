import google.generativeai as genai
import os


class GeminiIntegration:
    def __init__(self, model_name):
        # https://console.cloud.google.com/vertex-ai/generative/language/create/text?createType=code&project=gen-lang-client-0375481745
        # https://cloud.google.com/vertex-ai/generative-ai/docs/learn/models?_gl=1*x4pqgs*_ga*MTYyMTczNjUwMC4xNzE5MzE0MjQz*_ga_WH2QY8WWF5*MTcyMDIyMDU0NC44LjEuMTcyMDIyMDU0NS41OS4wLjA.&_ga=2.122733579.-1621736500.1719314243
        genai.configure(api_key='AIzaSyB54k37O691yozKJlOcE0bczSajg1F0Qw0')
        self.model = genai.GenerativeModel(model_name)

    def generate_content(self, prompt):
        # https://github.com/google-gemini/generative-ai-python/blob/main/samples/safety_settings.py
        response = self.model.generate_content(prompt, safety_settings={"HARASSMENT": "BLOCK_ONLY_HIGH"})
        return response.text
