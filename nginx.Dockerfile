FROM nginx

WORKDIR /app/nginx

COPY nginx.conf /app/nginx
COPY httptest /app/nginx