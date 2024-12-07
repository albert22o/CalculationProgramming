using System.Diagnostics;

namespace MatrixMultiplication
{
    class ResultsTable
    {
        private static object _lock = new object();

        private List<int> ControlValues;
        private long[] ResultsValuesStrassen;
        private long[] ResultValuesDefaultMultyply;
        private bool[] SignOfEquality;
        public ResultsTable(List<int> controlValues) 
        {
            ControlValues = controlValues;

            ResultsValuesStrassen = new long[ControlValues.Count];
            ResultValuesDefaultMultyply = new long[ControlValues.Count];
            SignOfEquality = new bool[ControlValues.Count];
        }

        private bool IsCorrectIndex(int index)
        {
            if(index < ControlValues.Count && index >= 0)
            {
                return true;
            }

            return false;
        }
        public void SetStrassenValue(int controlValueIndex, long elapsedMiliseconds)
        {
            lock(_lock)
            {
                if (IsCorrectIndex(controlValueIndex))
                {
                    ResultsValuesStrassen[controlValueIndex] = elapsedMiliseconds;
                }
                else
                {
                    throw new ArgumentOutOfRangeException("wrong index.");
                }
            }            
        }

        public void SetDefaultMultyplyValue(int controlValueIndex, long elapsedMiliseconds)
        {
            lock (_lock)
            {
                if (IsCorrectIndex(controlValueIndex))
                {
                    ResultValuesDefaultMultyply[controlValueIndex] = elapsedMiliseconds;
                }
                else
                {
                    throw new ArgumentOutOfRangeException("wrong index.");
                }
            }
        }

        public void SetEqualsSign(int controlValueIndex, bool isEqualsSign)
        {
            lock (_lock)
            {
                if (IsCorrectIndex(controlValueIndex))
                {
                    SignOfEquality[controlValueIndex] = isEqualsSign;
                }
                else
                {
                    throw new ArgumentOutOfRangeException("wrong index.");
                }
            }
        }

        public void DrawResultTable()
        {
            lock (_lock)
            {
                Console.Clear();

                Console.Write("{0,-20}", "N", -20);

                for (int i = 0; i < ControlValues.Count; i++)
                {
                    Console.Write($"{ControlValues[i],-20}");
                }

                Console.WriteLine();

                Console.Write("{0,-20}", "Strassen", -20);

                for (int j = 0; j < ControlValues.Count; j++)
                {
                    Console.Write($"{ResultsValuesStrassen[j],-20}");
                }

                Console.WriteLine();

                Console.Write("{0,-20}", "DefaultMultiply", -20);

                for (int j = 0; j < ControlValues.Count; j++)
                {
                    Console.Write($"{ResultValuesDefaultMultyply[j],-20}");
                }

                Console.WriteLine();

                Console.Write("{0,-20}", "IsEquals", -20);

                for (int j = 0; j < ControlValues.Count; j++)
                {
                    Console.Write($"{SignOfEquality[j],-20}");
                }
            }
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            var p = new Program();

            List<int> controlValues = new List<int>() {64, 100, 128, 256};

            ResultsTable resultsTable = new ResultsTable(controlValues);

            List<Task> tasks = new List<Task>();

            var factory = new TaskFactory();

            for (int i = 0; i < controlValues.Count; i++)
            {
                var parameters = new 
                {
                    ControlValueIndex = i,
                    ControlValue = controlValues[i],
                    ResultsTable = resultsTable 
                };

                var task = (factory.StartNew((param) => 
                {
                    var args = (dynamic)param;
                    p.CalcMatrixMultiplyTime(args.ControlValueIndex, args.ControlValue, args.ResultsTable); 
                }, 
                parameters));

                tasks.Add(task);
            }

            Task.WaitAll(tasks.ToArray());
        }

        public void CalcMatrixMultiplyTime(int controlValueIndex, int controlValue, ResultsTable resultsTable)
        {
            int n = controlValue;

            int[,] A = GenerateMatrixA(n);
            int[,] B = GenerateMatrixB(n);

            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();

            var strassen = MultiStrassen(A, B, n);
            stopwatch.Stop();

            resultsTable.SetStrassenValue(controlValueIndex, stopwatch.ElapsedMilliseconds);

            stopwatch.Reset(); 
            stopwatch.Start();

            var simpleMult = Multiply(A, B);

            stopwatch.Stop();

            resultsTable.SetDefaultMultyplyValue(controlValueIndex, stopwatch.ElapsedMilliseconds);

            resultsTable.SetEqualsSign(controlValueIndex, isMatrixEquals(strassen, simpleMult));

            resultsTable.DrawResultTable();     
        }

        public bool isMatrixEquals(int[,] A, int[,] B)
        {
            if (A.GetLength(0) != B.GetLength(0) || A.GetLength(1) != B.GetLength(1))
            {
                return false;
            }

            for (int i = 0; i < A.GetLength(0); i++)
            {
                for (int j = 0; j < A.GetLength(1); j++)
                {
                    if (A[i, j] != B[i, j])
                    {
                        return false;
                    }
                }
            }

            return true;
        }
        public int[,] GenerateMatrixA(int n)
        {
            int[,] A = new int[n, n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    A[i, j] = (int)Math.Pow(-1, i + j);
            return A;
        }

        public int[,] GenerateMatrixB(int n)
        {
            int[,] B = new int[n, n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    B[i, j] = (i + 1) + (j + 1);
            return B;
        }
        public void SplitMatrix(int[,] matrix, int[,] a11, int[,] a12, int[,] a21, int[,] a22)
        {
            int n = matrix.GetLength(0) / 2;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    a11[i, j] = matrix[i, j];
                    a12[i, j] = matrix[i, j + n];
                    a21[i, j] = matrix[i + n, j];
                    a22[i, j] = matrix[i + n, j + n];
                }
            }
        }
        public int[,] CollectMatrix(int[,] a11, int[,] a12, int[,] a21, int[,] a22)
        {
            int n = a11.GetLength(0);
            int[,] result = new int[n * 2, n * 2];

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    result[i, j] = a11[i, j];
                    result[i, j + n] = a12[i, j];
                    result[i + n, j] = a21[i, j];
                    result[i + n, j + n] = a22[i, j];
                }
            }

            return result;
        }
        public int[,] MultiStrassen(int[,] a, int[,] b, int n)
        {
            if (n <= 64)
            {
                return Multiply(a, b);
            }

            n /= 2;

            int[,] a11 = new int[n, n];
            int[,] a12 = new int[n, n];
            int[,] a21 = new int[n, n];
            int[,] a22 = new int[n, n];

            int[,] b11 = new int[n, n];
            int[,] b12 = new int[n, n];
            int[,] b21 = new int[n, n];
            int[,] b22 = new int[n, n];

            SplitMatrix(a, a11, a12, a21, a22);
            SplitMatrix(b, b11, b12, b21, b22);

            int[,] p1 = MultiStrassen(SumMatrix(a11, a22), SumMatrix(b11, b22), n);
            int[,] p2 = MultiStrassen(SumMatrix(a21, a22), b11, n);
            int[,] p3 = MultiStrassen(a11, SubMatrix(b12, b22), n);
            int[,] p4 = MultiStrassen(a22, SubMatrix(b21, b11), n);
            int[,] p5 = MultiStrassen(SumMatrix(a11, a12), b22, n);
            int[,] p6 = MultiStrassen(SubMatrix(a21, a11), SumMatrix(b11, b12), n);
            int[,] p7 = MultiStrassen(SubMatrix(a12, a22), SumMatrix(b21, b22), n);

            int[,] c11 = SumMatrix(SumMatrix(p1, p4), SubMatrix(p7, p5));
            int[,] c12 = SumMatrix(p3, p5);
            int[,] c21 = SumMatrix(p2, p4);
            int[,] c22 = SumMatrix(SubMatrix(p1, p2), SumMatrix(p3, p6));

            return CollectMatrix(c11, c12, c21, c22);
        }

        public int[,] SumMatrix(int[,] a, int[,] b)
        {
            int n = a.GetLength(0);

            int[,] result = new int[n, n];

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    result[i, j] = a[i, j] + b[i, j];
                }
            }

            return result;
        }
        public int[,] SubMatrix(int[,] a, int[,] b)
        {
            int n = a.GetLength(0);
            int[,] result = new int[n, n];

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    result[i, j] = a[i, j] - b[i, j];
                }
            }

            return result;
        }
        public int[,] Multiply(int[,] a, int[,] b)
        {
            int n = a.GetLength(0);

            int[,] result = new int[n, n];

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    result[i, j] = 0;

                    for (int k = 0; k < n; k++)
                    {
                        result[i, j] += a[i, k] * b[k, j];
                    }
                }
            }

            return result;
        }
    }
}
