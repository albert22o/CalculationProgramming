namespace GraphLabs
{
    internal class Program
    {
        const int INF = int.MaxValue;
        static void Main(string[] args)
        {
            int[,] graph = {
                {0, 25, 15, 7, 2},
                {25, 0, 6, 0, 0},
                {15, 6, 0, 4, 0},
                {7, 0, 4, 0, 3},
                {2, 0, 0, 3, 0}
            };

            int startVertex = 0;

            Dijkstra(graph, startVertex);

            Console.WriteLine();

            BellmanFord(graph, startVertex);
        }

        static List<int> GetPath(int vertex, int[] predecessor)
        {
            List<int> path = new List<int>();

            for (int at = vertex; at != -1; at = predecessor[at])
            {
                path.Insert(0, at);
            }

            return path;
        }

        static void PrintPath(List<int> path)
        {
            foreach (var vertex in path)
            {
                Console.Write(vertex + " ");
            }
        }

        static void BellmanFord(int[,] graph, int src)
        {
            int vertexCount = graph.GetLength(0);
            int[] dist = new int[vertexCount];
            int[] predecessor = new int[vertexCount];

            for (int i = 0; i < vertexCount; i++)
            {
                dist[i] = INF;
                predecessor[i] = -1;
            }

            dist[src] = 0;

            for (int i = 0; i < vertexCount - 1; i++)
            {
                for (int j = 0; j < vertexCount; j++)
                {
                    for (int k = 0; k < vertexCount; k++)
                    {
                        if (graph[j, k] != 0 && dist[j] != INF && dist[j] + graph[j, k] < dist[k])
                        {
                            dist[k] = dist[j] + graph[j, k];
                            predecessor[k] = j;
                        }
                    }
                }
            }

            for (int i = 0; i < vertexCount; i++)
            {
                for (int j = 0; j < vertexCount; j++)
                {
                    if (graph[i, j] != 0 && dist[i] != INF && dist[i] + graph[i, j] < dist[j])
                    {
                        Console.WriteLine("Граф содержит отрицательный цикл(ы)");
                        return;
                    }
                }
            }

            Console.WriteLine($"Белман Форд");

            for (int i = 0; i < vertexCount; i++)
            {
                if (dist[i] == INF)
                {
                    Console.WriteLine($"вершина {i} недостижима");
                }
                else
                {
                    Console.Write($"вершина {i}, расстояние = {dist[i]}, путь: ");
                    PrintPath(GetPath(i, predecessor));
                    Console.WriteLine();
                }
            }
        }

        static void Dijkstra(int[,] graph, int src)
        {
            int vertexCount = graph.GetLength(0);
            int[] dist = new int[vertexCount];
            int[] predecessor = new int[vertexCount];

            var queue = new PriorityQueue<(int Distance, int Vertex), int>();

            for (int i = 0; i < vertexCount; i++)
            {
                dist[i] = INF;
                predecessor[i] = -1;
            }

            dist[src] = 0;
            queue.Enqueue((0, src), 0);

            while (queue.Count > 0)
            {
                var (_, u) = queue.Dequeue();

                for (int v = 0; v < vertexCount; v++)
                {
                    if (graph[u, v] != 0 && dist[u] + graph[u, v] < dist[v])
                    {
                        dist[v] = dist[u] + graph[u, v];
                        predecessor[v] = u;
                        queue.Enqueue((dist[v], v), dist[v]);
                    }
                }
            }

            Console.WriteLine($"Дейкстра");

            for (int i = 0; i < vertexCount; i++)
            {
                if (dist[i] == INF)
                {
                    Console.WriteLine($"вершина {i} недостижима");
                }
                else
                {
                    Console.Write($"вершина {i}, расстояние = {dist[i]}, путь: ");
                    PrintPath(GetPath(i, predecessor));
                    Console.WriteLine();
                }
            }
        }
    }
}