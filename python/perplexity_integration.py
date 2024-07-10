import os
from openai import OpenAI


class PerplexityIntegration:
    def __init__(self):
        api_key = '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'
        self.client = OpenAI(api_key=api_key, base_url="https://api.perplexity.ai")

    def get_completion_content(self, prompt, selected_model):
        # https://docs.perplexity.ai/docs/getting-started
        # https://docs.perplexity.ai/docs/model-cards
        # https://deepmind.google/technologies/gemini/pro/
        # https://www.perplexity.ai/settings/api
        completion = self.client.chat.completions.create(
            model=selected_model,
            messages=[
                {"role": "user", "content": prompt}
            ]
        )
        return completion
#
# from openai import OpenAI
# client = OpenAI()

# completion = client.chat.completions.create(
#     model="gpt-4o",
#     messages=[
#         {"role": "user", "content": "Write java code to sum two numbers"}
#     ]
# )
#
# print(completion.choices[0].message.content)