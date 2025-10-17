FROM python:3.14-slim

WORKDIR /app

RUN apt-get update && apt-get install -y \
    git \
    && rm -rf /var/lib/apt/lists/*

RUN pip install --no-cache-dir flask

EXPOSE 5000

COPY hello.py .

CMD ["flask", "--app", "hello", "run", "--host=0.0.0.0"]