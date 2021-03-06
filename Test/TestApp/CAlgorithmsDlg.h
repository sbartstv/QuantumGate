// This file is part of the QuantumGate project. For copyright and
// licensing information refer to the license file(s) in the project root.

#pragma once

#include "CDialogBase.h"

class CAlgorithmsDlg : public CDialogBase
{
	DECLARE_DYNAMIC(CAlgorithmsDlg)

public:
	CAlgorithmsDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAlgorithmsDlg();

	void SetAlgorithms(QuantumGate::Algorithms* algs) noexcept { m_Algorithms = algs; }

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ALGORITHMS_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

	virtual BOOL OnInitDialog();
	
	afx_msg void OnBnClickedOk();

private:
	template<typename T>
	const bool HasAlgorithm(const Set<T>& list, const T value)
	{
		return (std::find(list.begin(), list.end(), value) != list.end());
	}

private:
	QuantumGate::Algorithms* m_Algorithms{ nullptr };
};
